class Solution {
    int dp[30005][2];
public:
    int rec(vector<int>&prices, int i, int p){
        int n = prices.size();

        if(i==n) return 0;

        if(dp[i][p]!=-1) return dp[i][p];

        int ans = 0;
        int t1 = rec(prices,i+1,1);
        int t2 = rec(prices,i+1,0);

        if(p){
            ans = max(-prices[i]+t2,t1);
        }else{
            ans = max(t2,prices[i]+t1);
        }

        return dp[i][p] = ans;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return rec(prices, 0,1);
    }
};
