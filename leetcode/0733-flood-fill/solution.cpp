class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>>ans = image;

        if(color==image[sr][sc]) return ans;

        queue<pair<int,int>>q;

        q.push({sr,sc});

        ans[sr][sc]=color;

        int tr = image[sr][sc];

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            int dr[] = {0,0,-1,1};
            int dc[] = {-1,1,0,0};

            for(int k=0;k<4;k++){
                int row = r+dr[k];
                int col = c+dc[k];

                if(row<0 || row>=n || col<0 || col>=m || ans[row][col]!=tr) continue;

                ans[row][col]=color;

                q.push({row,col});
            }
        }

        return ans;
    }
};
