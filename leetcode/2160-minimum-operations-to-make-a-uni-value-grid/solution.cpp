class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();

        vector<int>store;
        int md = -1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(md==-1){
                    md = grid[i][j]%x;
                }else if(md!=grid[i][j]%x){
                    return -1;
                }
                store.push_back(grid[i][j]);
            }
        }

        sort(store.begin(),store.end());

        vector<int>pref(n*m+1);

        for(int i=1;i<=n*m;i++){
            pref[i]+=pref[i-1]+store[i-1];
        }

        int mn = INT_MAX;

        for(int i=1;i<=n*m;i++){ 
            int left = ((i-1)*store[i-1])-pref[i-1];
            int right = pref[n*m]-pref[i]-((n*m-i)*store[i-1]);

            mn = min(mn,(left+right)/x);
        }

        return mn;
    }
};
