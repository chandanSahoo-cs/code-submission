class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int>dp0(n+2),dp1(n+2);

        for(int i=n-1;i>=0;i--){
            dp1[i] = max(dp1[i+1],nums[i]+dp1[i+2]);
            if(i<n-1){
                dp0[i] = max(dp0[i+1],nums[i]+dp0[i+2]);
            }
        }

        return max(dp0[0],dp1[1]);
    }
};
