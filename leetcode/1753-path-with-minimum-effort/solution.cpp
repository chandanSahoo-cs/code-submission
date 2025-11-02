class Solution {
    const int INF = 1e8;
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INF));

        set<vector<int>>st;
        // v[0] = total cost up to now
        // v[1] = row
        // v[2] = col
        st.insert({0,0,0});
        dist[0][0]=0;

        while(!st.empty()){
            vector<int>v = *st.begin();
            st.erase(v);

            int currR = v[1];
            int currC = v[2];
            int tot = v[0];

            int dr[] = {0,0,-1,1};
            int dc[] = {-1,1,0,0};

            for(int k=0;k<4;k++){
                int r = currR+dr[k];
                int c = currC+dc[k];

                if(r>=n || c>=m || r<0 || c<0) continue;

                int d = dist[r][c];
                int diff = abs(h[currR][currC]-h[r][c]);

                if(d>max(tot,diff)){
                    st.erase({d,r,c});
                    dist[r][c] = max(tot,diff);
                    st.insert({max(tot,diff),r,c});
                }
            }
        }

        return dist[n-1][m-1];
    }
};
