class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;

        int n = ans.size();
        int m = ans[0].size();

        vector<vector<int>>vis(n,vector<int>(m));
        stack<pair<int,int>>st;

        ans[sr][sc]=color;
        st.push({sr,sc});

        int inColor = image[sr][sc];

        while(!st.empty()){
            pair<int,int>pr = st.top();
            st.pop();

            int r = pr.first;
            int c =pr.second;
            vis[r][c] = 1;

            vector<int>dr = {0,0,1,-1};
            vector<int>dc = {1,-1,0,-0};

            for(int k=0;k<4;k++){
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr>=n || nr<0 || nc>=m || nc<0 || vis[nr][nc] || ans[nr][nc]!=inColor) continue;
                ans[nr][nc] = color;
                st.push({nr,nc});
            }

        }
        return ans;
    }
};
