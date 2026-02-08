class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);      // global visited
        vector<int> time(n, 0);     // time within traversal
        int mx = -1;
        int timer = 1;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int node = i;
            int startTime = timer;

            while (node != -1 && !vis[node]) {
                vis[node] = 1;
                time[node] = timer++;
                node = edges[node];
            }

            // If we found a cycle in THIS traversal
            if (node != -1 && time[node] >= startTime) {
                mx = max(mx, timer - time[node]);
            }
        }
        return mx;
    }
};

