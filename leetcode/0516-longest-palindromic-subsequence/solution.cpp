class Solution {
    int dp[1005][1005];
public:
    int rec(string &s, int l, int r){
        if(l>r) return 0;
        if(l==r) return 1;

        if(dp[l][r]!=-1) return dp[l][r];

        int ans=0;
        

        if(s[l]==s[r]){
            ans = max(ans,2+rec(s,l+1,r-1));
        }else{
            ans = max(ans,rec(s,l+1,r));
            ans = max(ans,rec(s,l,r-1));
        }

        return dp[l][r] = ans;
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();

        memset(dp,-1,sizeof(dp));
        return rec(s,0,n-1);
    }
};
