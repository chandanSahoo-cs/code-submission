class Solution {
    int dp[1005][2000];
public:

    int rec(vector<int>&a, int i,int t, int k){
        int n = a.size();
        if(t==2*k || i==n) return 0;

        if(dp[i][t]!=-1) return dp[i][t];

        int ans = 0;

        if(t%2==0){
            ans = max(rec(a,i+1,t,k),-a[i]+rec(a,i+1,t+1,k));
        }else{
            ans = max(a[i]+rec(a,i+1,t+1,k),rec(a,i+1,t,k));
        }

        return dp[i][t]=ans; 
    }

    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return rec(prices,0,0,k);
    }
};
