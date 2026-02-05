const int mod = 1e9+7;

class Solution {
public:

    int peopleAwareOfSecret(int n, int d, int f) {
        vector<int>dp(n+1);
        vector<int>pref(n+2,0);
        pref[n]=1;
        dp[n]=1;

        for(int i=n-1;i>=1;i--){
            int l = i+d;
            int r = i+f-1;

            int cnt = r>=n;

            if(l<=n){
                cnt = (cnt+pref[l]-pref[min(r,n)+1]+mod)%mod;
            }

            dp[i] = cnt;
            pref[i] = (dp[i]+pref[i+1])%mod;
        }

        return dp[1];
    }
};
