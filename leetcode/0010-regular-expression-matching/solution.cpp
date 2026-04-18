class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        vector<vector<bool>>dp(n+1,vector<bool>(m+1));
        dp[n][m] = true;

        for(int i=n;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(p[j]=='*') continue;
                bool flag = false;

                if(i<n && (s[i]==p[j] || (s[i]!=p[j] && p[j]=='.')) && (j==m-1 || p[j+1]!='*')){
                    flag |= dp[i+1][j+1];
                }

                if(j<m-1 && p[j+1]=='*'){
                    flag |= dp[i][j+2];
                    int t = i;
                    while(t<n && (s[t]==p[j] || p[j]=='.')){
                        flag |= dp[t+1][j+2];
                        t++;
                    }
                }

                dp[i][j] = flag;
            }
        }

        return dp[0][0];    
    }
};
