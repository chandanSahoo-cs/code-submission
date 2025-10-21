class Solution {
    int dp[305][305];

    int rec(vector<int>&a, int l, int r){
        if(r-l==1) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];

        int ans = 0;

        for(int i=l+1;i<r;i++){
            ans = max(ans,a[l]*a[i]*a[r]+rec(a,l,i)+rec(a,i,r));
        }

        return dp[l][r] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int>a(n+2,1);

        for(int i=1;i<=n;i++){
            a[i] = nums[i-1];
        }
        memset(dp,-1,sizeof(dp));

        return rec(a,0,n+1);
        
    }
};
