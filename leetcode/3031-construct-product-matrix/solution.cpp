const int mod = 12345;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<int>flat(n*m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                flat[i*m+j] = grid[i][j];
            }
        }

        vector<int>pref=flat, suff=flat;

        for(int i=1;i<n*m;i++){
            pref[i] = (pref[i]*1LL*pref[i-1])%mod;
        }

        for(int i=n*m-2;i>=0;i--){
            suff[i] = (suff[i]*1LL*suff[i+1])%mod;
        }

        vector<vector<int>>ans(n,vector<int>(m));
        
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                int ind = i*m+j;
                ans[i][j] = 1;
                
                if(ind>0){
                    ans[i][j] = (ans[i][j]*1LL*pref[ind-1])%mod;
                }

                if(ind<n*m-1){
                    ans[i][j] = (ans[i][j]*1LL*suff[ind+1])%mod;
                }
            }
        }

        return ans;
    }
};
