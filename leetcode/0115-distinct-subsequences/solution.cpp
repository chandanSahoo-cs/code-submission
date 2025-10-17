class Solution {
    int dp[1005][1005];
public:

    int rec(string &s, string &t,int i,int j){
        int n = s.size();
        int m = t.size();

        if(j==m) return 1;
        if(i==n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=rec(s,t,i+1,j);

        if(s[i]==t[j]){
            ans+=rec(s,t,i+1,j+1);
        }

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                dp[i][j]=-1;
            }
        }
        return rec(s,t,0,0);
    }
};
