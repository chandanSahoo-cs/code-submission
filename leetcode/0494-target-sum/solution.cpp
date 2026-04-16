class Solution {
public:
    int dp[25][4005];
    int buffer = 2000;

    int rec(vector<int>& nums, int target, int i){
        int n = nums.size();

        if(i==n){
            if(target==0) return 1;
            return 0;
        }

        if(dp[i][target+buffer]!=-1) return dp[i][target+buffer];

        return dp[i][target+buffer] = rec(nums,target-nums[i],i+1)+rec(nums,target+nums[i],i+1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,target,0);    
    }
};
