class Solution {
    // int dp[3005][5005];
    int mod = 1e9+7;
public:
    // int rec(vector<int>&a, int amt, int i){
    //     int n = a.size();
    //     if(i==n) return amt==0;
    //     if(dp[i][amt]!=-1) return dp[i][amt];

    //     int ans = 0;
    //     ans+=rec(a,amt,i+1);

    //     if(amt-a[i]>=0){
    //         ans+=rec(a,amt-a[i],i);
    //     }

    //     return dp[i][amt] = ans;
    // }
    

    int change(int amt, vector<int>& a) {
        int n = a.size();

        vector<vector<unsigned int>>dp(n+1,vector<unsigned int>(amt+1,0));

        dp[n][0] = 1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=amt;j++){
                dp[i][j] += dp[i+1][j];
                if(j-a[i]>=0){
                    dp[i][j] +=dp[i][j-a[i]];
                }
            }
        }

        return dp[0][amt];
    }
};

