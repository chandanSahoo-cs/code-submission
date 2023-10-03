class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for(int index=0;index<nums.size();index++){
            nums[index]+=nums.size()*(nums[nums[index]]%nums.size());
        }
        for(int index=0;index<nums.size();index++){
            nums[index]/=nums.size();
        }
        return nums;
    }
};
