class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxSum=INT_MIN;
        int currSum=0;
        
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(currSum+nums[i]<nums[i]){
                currSum=nums[i];
            }else currSum+=nums[i];

            mxSum = max(mxSum,currSum);
        }

        return mxSum;
    }
};
