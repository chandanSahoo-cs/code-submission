class Solution {
    #define ll long long
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        ll s=0,e=nums.size()-1;
        while(s<=e){
            ll m=s+(e-s)/2;
            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1]){
                return nums[m];
                break;
            }
            else if(nums[m]==nums[m-1] && m%2!=0) s=m+1;
            else if(nums[m]==nums[m+1] && m%2==0) s=m+2;
            else if(nums[m]==nums[m+1] && m%2!=0) e=m-1;
            else e=m-2;
        }
        return -1;
    }
};
