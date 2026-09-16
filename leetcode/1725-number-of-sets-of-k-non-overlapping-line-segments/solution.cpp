
const int mod = 1e9+7;

class Solution {
public:

    // int rec(int n, int i, int k){
    //     if(k==0) return 1;
    //     if(i>=n) return 0;

    //     int cnt = rec(n,i+1,k);

    //     for(int j=i+1;j<n;j++){
    //         cnt = (cnt+rec(n,j,k-1))%mod;
    //     }

    //     return dp[i][k] = cnt;
    // }

    int numberOfSets(int n, int k) {

        vector<vector<int>>dp(k+1,vector<int>(n+1));
        
        for(int i=0;i<=n;i++){
            dp[0][i] = 1;
        }

        for(int i=0;i<k;i++){
            dp[i][n] = 0;
        }


        for(int nk=1; nk<=k;nk++){
            vector<int>suff(n+1);

            for(int i=n-1;i>=0;i--){
                suff[i] = (suff[i+1]+dp[nk-1][i])%mod;
            }
            for(int i=n-1;i>=0;i--){
                int cnt = (dp[nk][i+1]+suff[i+1])%mod;
                dp[nk][i] = cnt;
            }
        }

        return dp[k][0];    
    }
};

