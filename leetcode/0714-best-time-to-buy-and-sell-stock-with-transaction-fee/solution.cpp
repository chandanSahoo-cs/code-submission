class Solution {
    int dp[50005][2];
public:

    int rec(vector<int>&a,int i, int p, int fee){
        int n = a.size();

        if(i==n) return 0;
        if(dp[i][p]!=-1) return dp[i][p];

        int ans = 0;

        int t1 = rec(a,i+1,0, fee);
        int t2 = rec(a,i+1,1, fee);

        if(p){
            ans = max(t2,-a[i]+t1);
        }else{
            ans = max(t1,a[i]+t2-fee);
        }

        return dp[i][p] = ans;
    }

    int maxProfit(vector<int>& a, int fee) {
        memset(dp,-1,sizeof(dp));

        return rec(a,0,1,fee);
    }
};
