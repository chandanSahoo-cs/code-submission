class Solution {
int dp[205][20005];

public:
    int rec(vector<int>&a, int tot, int curr, int i){
        int n = a.size();
        if(curr+curr==tot) return 1;
        if(i==n || curr+curr<tot) return 0;

        if(dp[i][curr]!=-1) return dp[i][curr];

        int ans = rec(a,tot,curr-a[i],i+1) || rec(a,tot,curr,i+1);

        return dp[i][curr] = ans;
    }

    bool canPartition(vector<int>& a) {
        int sum = accumulate(a.begin(),a.end(),0);

        if(sum%2) return 0;

        memset(dp,-1,sizeof(dp));

        return rec(a,sum,sum,0);
    }
};
