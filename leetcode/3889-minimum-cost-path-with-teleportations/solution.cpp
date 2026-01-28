const int INF = 1e9+7;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>sspace(n*m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sspace[i*m+j]=grid[i][j];
            }
        }

        sort(sspace.begin(),sspace.end());

        vector<int>dp(n*m,INF);
        vector<int>next(n*m,INF);

        for(int moves=0;moves<=k;moves++){

            vector<pair<int,int>>v;

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    v.push_back({grid[i][j],next[i*m+j]});
                }
            }

            sort(v.begin(),v.end());

            for(int i=0;i<n*m;i++){
                next[i] = v[i].second;
            }

            for(int i=1;i<n*m;i++){
                next[i]=min(next[i],next[i-1]);
            }

            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    int ind = i*m+j;

                    if(i==n-1 && j==m-1){
                        dp[ind]=0;
                        continue;
                    }

                    if(i<n-1){
                        dp[ind] = min(dp[ind],grid[i+1][j]+dp[(i+1)*m+j]);
                    }

                    if(j<m-1){
                        dp[ind] = min(dp[ind],grid[i][j+1]+dp[(i*m+j+1)]);
                    }

                    auto magItr = upper_bound(sspace.begin(),sspace.end(),grid[i][j]);
                    magItr--;

                    int magInd = magItr-sspace.begin();

                    dp[ind] = min(dp[ind],next[magInd]);
                }
            }

            next = dp;
            dp = vector<int>(n*m,INF);
        }
        
        return next[0];
    }
};
