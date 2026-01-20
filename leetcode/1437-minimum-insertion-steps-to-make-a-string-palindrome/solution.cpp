class Solution {
public:
    int dp[505][505];

    int rec(string &s, int l, int r){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        int ans = min(rec(s,l+1,r),rec(s,l,r-1))+1;

        if(s[l]==s[r]){
            ans = min(ans,rec(s,l+1,r-1));
        }

        return dp[l][r] = ans;
    }

    int minInsertions(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));

        return rec(s,0,n-1);
    }
};
