class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        auto maxValue=max_element(nums.begin(),nums.end());
        vector<int>freq(*maxValue+1,0);
        for(auto ele:nums){
            count+=freq[ele];
            freq[ele]++;
        }
        return count;
    }
};
