class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1;

        while(l<=r){
            int m = l+(r-l)/2;
            
            if((m==0 || nums[m]!=nums[m-1]) && (m==nums.size()-1 || nums[m]!=nums[m+1])) return nums[m];
            else if((m%2 && nums[m]==nums[m-1]) || (m%2==0 && nums[m]==nums[m+1])){
                l=m+1;
            }else r=m-1;
        }

        return -1;
    }
};
