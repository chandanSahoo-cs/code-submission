class Solution {
public:
    bool isMatch(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(s1==""){
            for(auto ele:s2){
                if(ele!='*') return 0;
            }
            return 1;
        }

        int last= -1;
        for(int i=m-1;i>=0;i--){
            if(s2[i]!='*'){
                last= i+1;
                break;
            }
        }

        vector<vector<int>>dp(n+1,vector<int>(m+1));

        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n && j==m) dp[i][j]=1;
                else if(i==n || j==m){
                    if(i==n){
                        dp[i][j]= j>=last;
                    }
                }else{
                    int ans = 0;
                    if(s1[i]==s2[j] || s2[j]=='?'){
                        ans = dp[i+1][j+1];
                    }else if(s2[j]=='*'){
                        ans = dp[i+1][j] || dp[i][j+1];
                    }
                    dp[i][j]=ans;
                }
            }
        }

        return dp[0][0];
    }
};
