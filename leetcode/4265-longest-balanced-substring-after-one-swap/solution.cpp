/*code by gokuu*/

class Solution {
public:
    int longestBalanced(string s) {
        const int n = (int) s.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (s[i] - '0' ? +1 : -1);
        }
        vector<int> pre0(n + 1), pre1(n + 1);
        for (int i = 0; i < n; ++i) {
            pre0[i + 1] = pre0[i] + (s[i] == '0');
            pre1[i + 1] = pre1[i] + (s[i] == '1');
        }
        unordered_map<int, int> r;
        for (int i = 0; i <= n; ++i) {
            r[pre[i]] = i;
        }
        unordered_map<int, int> l;
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (l.find(pre[i]) == l.end()) l[pre[i]] = i;
            else {
                ans = max(ans, i - l[pre[i]]);
            }
            if (r.find(pre[i] + 2) != r.end()) {
                int j = r[pre[i] + 2];
                if (j > 0 && pre1[j - 1] - pre1[i] > 0 && pre0[i] > 0) {
                    ans = max(ans, j - i);
                }
            }
            if (r.find(pre[i] - 2) != r.end()) {
                int j = r[pre[i] - 2];
                if (j > 0 && pre0[j - 1] - pre0[i] > 0 && pre1[i] > 0) {
                    ans = max(ans, j - i);
                }
            }
            if (pre1[n] - pre1[i] > 0 && pre0[i] > 0) {
                if (l.find(pre[i] + 2) != l.end()) {
                    ans = max(ans, i - l[pre[i] + 2]);
                }
            }
            if (pre0[n] - pre0[i] > 0 && pre1[i] > 0) {
                if (l.find(pre[i] - 2) != l.end()) {
                    ans = max(ans, i - l[pre[i] - 2]);
                }
            }
        }
        return ans;
    }
};
