class Solution {
int dp[105];    
public:
    int rec(int n, vector<int>&a, int i){
        if(i>=n) return 0;
        if(i==n-1) return a[i];

        if(dp[i]!=-1) return dp[i];
        int ans=0;
        //take
        ans = max(ans,a[i]+rec(n,a,i+2));
        // not take
        ans = max(ans,rec(n,a,i+1));

        return dp[i] = ans;
    }

    int rob(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        return rec(a.size(),a,0);
    }
};
