class Solution {
public:
    const int mod = 1e9+7;
    int dp[2005];
    
    int rec(vector<vector<int>>&a, string &s, int i){
        int n = s.size();

        if(i>=n) return 1;

        if(dp[i]!=-1) return dp[i];
        int cnt = 0;

        for(int j=0;j<26;j++){
            if(a[i][j]==-1) continue;
            cnt = (cnt+rec(a,s,a[i][j]+1))%mod;
        }

        return dp[i] = (cnt+1)%mod;
    }

    int distinctSubseqII(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));

        vector<vector<int>>a(n,vector<int>(26,-1));

        a[n-1][s[n-1]-'a']=n-1;

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<26;j++){
                a[i][j] = a[i+1][j];
            }
            a[i][s[i]-'a'] = i; 
        }

        return (rec(a,s,0)-1+mod)%mod;
    }
};
