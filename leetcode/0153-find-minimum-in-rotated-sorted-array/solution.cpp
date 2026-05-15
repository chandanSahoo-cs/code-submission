class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;

        int ans = r;
        while(l<=r){
            int m = l+(r-l)/2;

            if(nums[m]>nums[r]) l=m+1;
            else{
                if(nums[m]<nums[ans]){
                    ans = m;
                }
                r = m-1;
            }
        }

        return nums[ans];
    }
};
