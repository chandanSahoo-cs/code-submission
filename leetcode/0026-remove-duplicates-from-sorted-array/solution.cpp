class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqueValue=1;
        if(nums.size()==0) return 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[uniqueValue]=nums[i];
                uniqueValue++;
            }
        }
        return uniqueValue;
    }
};
