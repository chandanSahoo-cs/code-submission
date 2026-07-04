class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;

        int cnt = 0;

        for(auto ele:nums){
            cnt+=(ele==nums[mid]);
        }

        return cnt==1;
    }
};
