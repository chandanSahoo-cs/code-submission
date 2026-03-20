class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1));

        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                vector<int>store;

                for(int ni=i;ni<i+k;ni++){
                    for(int nj=j;nj<j+k;nj++){
                        store.push_back(grid[ni][nj]);
                    }
                }

                sort(store.begin(),store.end());
                int mn=INT_MAX;

                for(int l=0;l<store.size()-1;l++){
                    if(store[l]==store[l+1]) continue;
                    mn = min(mn,abs(store[l+1]-store[l]));
                }

                ans[i][j]=(mn==INT_MAX?0:mn);
            }
        }

        return ans;
    }
};
