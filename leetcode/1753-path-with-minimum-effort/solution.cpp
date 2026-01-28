const int INF = 1e9+7;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size(),m = heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INF));

        set<tuple<int,int,int>>st;

        st.insert({0,0,0});
        dist[0][0]=0;

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        while(!st.empty()){
            auto [cost,i,j] = *st.begin();
            st.erase(st.begin());

            for(int k=0;k<4;k++){
                int r = i+dr[k];
                int c = j+dc[k];

                if(r<0 || r>=n || c<0 || c>=m) continue;

                int h = max(cost,abs(heights[r][c]-heights[i][j]));

                if(h<dist[r][c]){
                    st.erase({dist[r][c],r,c});
                    dist[r][c] = h;

                    st.insert({h,r,c});
                }
            }
        }

        return dist[n-1][m-1];
    }
};
