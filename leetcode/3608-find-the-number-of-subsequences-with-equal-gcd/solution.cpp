const int mod = 1e9+7;
class Solution {
public:
    int dp[205][205][205];

    int rec(vector<int>&nums, int i, int val1, int val2){
        int n = nums.size();
        
        if(i>=n) return val1==val2 && val1<=200 && val2<=200;

        if(dp[i][val1][val2]!=-1) return dp[i][val1][val2];

        int ans = 0;
        
        // not take
        ans = (ans+rec(nums,i+1,val1,val2))%mod;

        // take
        int p1 = val1<=200?gcd(val1,nums[i]):nums[i];
        ans = (ans+rec(nums,i+1,p1,val2))%mod;

        int p2 = val2<=200?gcd(val2,nums[i]):nums[i];
        ans = (ans+rec(nums,i+1,val1,p2))%mod;

        return dp[i][val1][val2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,0,201,201);
    }
};
