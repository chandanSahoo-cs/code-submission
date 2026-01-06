class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n-1;

        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]==target) return true;
            else if(nums[l]==nums[m] && nums[m]==nums[r]){
                l++;
                r--;
            }else if(nums[m]>nums[r]){
                if(target>=nums[l] && target<=nums[m]){
                    r=m-1;
                }else l=m+1;
            }else{
                if(target>=nums[m] && target<=nums[r]){
                    l=m+1;
                }else r=m-1;
            }
        }

        return false;
    }
};
