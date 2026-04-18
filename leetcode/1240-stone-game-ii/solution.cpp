class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int>pref = piles;

        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1];
        }

        vector<vector<int>>dp(n+1,vector<int>(n+1));

        for(int i=n-1;i>=0;i--){
            for(int m=n;m>=1;m--){
                int mx = 0;
                for(int j=1;j<=2*m && i+j-1<n;j++){
                    int curr = pref[i+j-1]-(i>0?pref[i-1]:0);
                    int s = dp[i+j][max(m,j)];

                    mx = max(mx,curr+pref[n-1]-pref[i+j-1]-s);

                    dp[i][m] = mx;
                }
            }
        }

        return dp[0][1];
    }
};
