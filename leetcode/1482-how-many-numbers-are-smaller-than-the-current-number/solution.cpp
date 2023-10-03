class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        auto maxValue = max_element(nums.begin(), nums.end());
        vector<int> ans(nums.size());
        vector<int> freq(*maxValue + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for (int i = 1; i < freq.size(); i++) {
            freq[i] += freq[i - 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans[i] = freq[nums[i] - 1];
            }
        }

        return ans;
    }
};

