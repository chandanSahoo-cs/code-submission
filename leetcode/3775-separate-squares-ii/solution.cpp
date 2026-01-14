class Solution {
public:
    struct Event {
        double y;
        int type;      // +1 = add, -1 = remove
        int l, r;      // x-index range in compressed coords
    };

    struct SegTree {
        int n;
        vector<int> cover;
        vector<double> len;
        vector<double> xs;

        SegTree(int n, vector<double> &xs) : n(n), xs(xs) {
            cover.assign(4 * n, 0);
            len.assign(4 * n, 0.0);
        }

        void pull(int node, int l, int r) {
            if (cover[node] > 0) {
                len[node] = xs[r + 1] - xs[l];
            } else if (l == r) {
                len[node] = 0.0;
            } else {
                len[node] = len[node * 2] + len[node * 2 + 1];
            }
        }

        void update(int node, int l, int r, int ql, int qr, int val) {
            if (qr < l || r < ql) return;
            if (ql <= l && r <= qr) {
                cover[node] += val;
                pull(node, l, r);
                return;
            }
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid + 1, r, ql, qr, val);
            pull(node, l, r);
        }

        double query() {
            return len[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<double> xs;
        vector<Event> events;

        // Collect x-coordinates
        for (auto &s : squares) {
            xs.push_back(s[0]);
            xs.push_back(s[0] + s[2]);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto getX = [&](double x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        // Build events
        for (auto &s : squares) {
            double x = s[0], y = s[1], l = s[2];
            int L = getX(x);
            int R = getX(x + l) - 1;
            events.push_back({y, +1, L, R});
            events.push_back({y + l, -1, L, R});
        }

        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a.y < b.y;
        });

        SegTree st(xs.size() - 1, xs);

        // ---- First sweep: total union area ----
        double totalArea = 0.0;
        double prevY = events[0].y;

        for (auto &e : events) {
            double dy = e.y - prevY;
            totalArea += st.query() * dy;
            st.update(1, 0, st.n - 1, e.l, e.r, e.type);
            prevY = e.y;
        }

        // ---- Second sweep: find split Y ----
        st = SegTree(xs.size() - 1, xs);
        double half = totalArea / 2.0;
        double area = 0.0;
        prevY = events[0].y;

        for (auto &e : events) {
            double dy = e.y - prevY;
            double width = st.query();
            double add = width * dy;

            if (area + add >= half) {
                return prevY + (half - area) / width;
            }

            area += add;
            st.update(1, 0, st.n - 1, e.l, e.r, e.type);
            prevY = e.y;
        }

        return prevY; // fallback (should not hit)
    }
};

