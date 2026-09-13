class Solution {
public:

    int dp[100005];

    int rec(int n){
        if(n==0) return -1;

        if(dp[n]!=-1) return dp[n];

        int curr = 0;
        int ans = INT_MAX;

        for(int i=1;i<448;i++){
            curr+=i;
            if(curr>n) break;

            ans = min(ans,1+i+rec(n-curr));
        }

        return dp[n] = ans;
    }

    int minDays(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n);
    }
};

