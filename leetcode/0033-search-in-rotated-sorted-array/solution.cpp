class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        int pivot = r;

        while(l<=r){
            int m = l+(r-l)/2;

            if(nums[m]>nums[r]) l=m+1;
            else {
                if(nums[pivot]>nums[m]){
                    pivot = m;
                }
                r = m-1;
            }
        }

        if(nums[0]<=target && pivot-1>=0 && nums[pivot-1]>=target){
            l = 0, r = pivot-1;
        }else{
            l = pivot;
            r = n-1;
        }


        while(l<=r){
            int m = l+(r-l)/2;

            if(nums[m]==target) return m;
            else if(nums[m]>target) r = m-1;
            else l = m+1;
        }

        return -1;
    }
};
