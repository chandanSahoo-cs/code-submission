class Solution {
    int dp[25][4005];
    int BUFFER = 2005;
public:

    int rec(vector<int>&a, int t, int i){
        int n = a.size();

        if(i==n) return t==0;
        if(dp[i][t+BUFFER]!=-1) return dp[i][t+BUFFER];

        int ans = rec(a,t-a[i],i+1)+rec(a,t+a[i],i+1);

        return dp[i][t+BUFFER]=ans;
    }

    int findTargetSumWays(vector<int>& a, int target) {
        memset(dp,-1,sizeof(dp));

        return rec(a,target,0);
    }
};
