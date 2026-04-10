class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long>dp(target+1);
        dp[0]=1;

        for(int i=1;i<=target;i++){
            for(auto ele:nums){
                dp[i]+=(i-ele>=0)?dp[i-ele]:0LL;
            }
        }

        return dp[target]; 
    }
};
