class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>>dp(n+1);
        dp[n]={1,1};

        int mx = INT_MIN;

        for(int i=n-1;i>=0;i--){
            auto [mxx,mnn] = dp[i+1];

            if(nums[i]>0){
                dp[i] = {max(nums[i],nums[i]*mxx),min(nums[i],nums[i]*mnn)};
            }else{
                dp[i] = {max(nums[i],nums[i]*mnn),min(nums[i],nums[i]*mxx)};
            }

            mx = max(mx,dp[i].first);
        }

        return mx;
    }
};
