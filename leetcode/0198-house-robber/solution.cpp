#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return robHelper(nums, n - 1, memo);
    }

private:
    int robHelper(const vector<int>& nums, int i, vector<int>& memo) {
        if (i < 0) {
            return 0;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        int robCurrent = nums[i] + robHelper(nums, i - 2, memo);
        int skipCurrent = robHelper(nums, i - 1, memo);

        memo[i] = max(robCurrent, skipCurrent);
        return memo[i];
    }
};

