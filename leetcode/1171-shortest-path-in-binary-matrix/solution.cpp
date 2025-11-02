class Solution {
    const int INF=1e5;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]) return -1;

        set<vector<int>>st;
        st.insert({1,0,0});
        vector<vector<int>>dist(n,vector<int>(n,INF));
        dist[0][0]=1;

        while(!st.empty()){
            vector<int>v = *st.begin();
            st.extract(v);

            for(int rk=-1;rk<=1;rk++){
                for(int ck=-1;ck<=1;ck++){
                    if(rk==0 && ck==0) continue;
                    int r = v[1]+rk;
                    int c = v[2]+ck;

                    if(r>=n || c>=n || r<0 || c<0 || grid[r][c]) continue;

                    if(dist[r][c]>v[0]+1){
                        st.extract({dist[r][c],r,c});
                        dist[r][c]=v[0]+1;
                        st.insert({v[0]+1,r,c});
                    }
                }
            }
        }


        return dist[n-1][n-1]==1e5?-1:dist[n-1][n-1];
    }
};
