class Solution {
    int dp[505][505];
public:

    int rec(string &s, int l, int r){
        if(l>r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int ans = 1e9;

        if(s[l]==s[r]){
            ans = rec(s,l+1,r-1);
        }else{
            ans = min(ans,1+rec(s,l+1,r));
            ans = min(ans,1+rec(s,l,r-1));
        }

        return dp[l][r] = ans;

    }

    int minInsertions(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));

        return rec(s,0,n-1);
    }
};
