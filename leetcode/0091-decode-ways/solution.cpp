class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+2);
        dp[n]=dp[n+1]=1;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
                continue;
            }
            int ans = dp[i+1];

            if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))) ans+=dp[i+2];
            dp[i] = ans;
        }

        return dp[0];
    }
};
