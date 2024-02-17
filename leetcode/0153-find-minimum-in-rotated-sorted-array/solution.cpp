class Solution {
    #define ll long long
public:
    int findMin(vector<int>& nums) {
        ll s=0,e=nums.size()-1;
        if(nums[s]>nums[e]){
            while(s<=e){
                ll m=s+(e-s)/2;
                if(nums[m]>=nums[s] && nums[m]>=nums[e] && nums[m]>nums[m+1]) return nums[m+1];
                else if(nums[m]<nums[s]) e=m-1;
                else s=m+1;
            }
        }
        else return nums[0];
        return -1;
    }
};
