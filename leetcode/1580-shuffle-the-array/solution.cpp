class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int val) {
        for(int i = 0; i < val; i++)  nums[i] += nums[val + i] * 1001;
       
        for(int i = val - 1; i >= 0; i--){
            nums[2 * i + 1] = nums[i] / 1001;
            nums[2 * i] = nums[i] % 1001;
        }
        return nums;
    }
};

