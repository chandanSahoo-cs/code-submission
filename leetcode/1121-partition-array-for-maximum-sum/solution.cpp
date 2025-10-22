class Solution {
    int dp[505];

    int rec(vector<int>&a, int k, int i){
        int n = a.size();

        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];

        int ans = 0;
        int mx = -1;
        for(int j=i;j<min(n,i+k);j++){
            mx = max(mx,a[j]);
            ans = max(ans,mx*(j-i+1)+rec(a,k,j+1));
        }

        return dp[i] = ans;
    }

public:
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        memset(dp,-1,sizeof(dp));

        return rec(a,k,0);
    }
};
