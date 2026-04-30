class Solution {
public:

    pair<int,int> scoreAndCost(int num){
        if(num==1) return {1,1};
        if(num==2) return {2,1};
        return {0,0};
    }
    
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>>curr(m+1,vector<int>(k+1));
        vector<vector<int>>next(m+1,vector<int>(k+1,-1));

        for(int i=0;i<=k;i++){
            auto [score,cost] = scoreAndCost(grid[n-1][m-1]);
            curr[m-1][i] = i-cost>=0?score:-1;
            curr[m][i] = -1;
        }


        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;
                for(int l=0;l<=k;l++){
                    auto [score,cost] = scoreAndCost(grid[i][j]);
                    if(l-cost>=0){
                        int mx = max(curr[j+1][l-cost],next[j][l-cost]);

                        curr[j][l] = mx==-1?-1:score+mx;
                    }else{
                        curr[j][l] = -1;
                    }
                }
            }
            next = curr;
        }

        return next[0][k];
    }
};
