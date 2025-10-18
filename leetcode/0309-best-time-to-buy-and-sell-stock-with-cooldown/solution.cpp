class Solution {
int dp[5005][2];
public:

    int rec(vector<int>&a, int i, int p){
        int n = a.size();

        if(i>=n) return 0;

        if(dp[i][p]!=-1) return dp[i][p];

        int ans = 0;

        if(p){
            ans = max(rec(a,i+1,1),-a[i]+rec(a,i+1,0));
        }else{
            ans = max(rec(a,i+1,0),a[i]+rec(a,i+2,1));
        }

        return dp[i][p] = ans;
    }

    int maxProfit(vector<int>& a) {
        memset(dp,-1,sizeof(dp));

        return rec(a,0,1);
    }
};
