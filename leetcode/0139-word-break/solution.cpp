class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(n+1);
        dp[n]=1;

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                dp[i] = dp[i] || (st.count(s.substr(i,j-i+1)) && dp[j+1]);
                if(dp[i]) break;
            }
        }

        return dp[0];
    }
};
