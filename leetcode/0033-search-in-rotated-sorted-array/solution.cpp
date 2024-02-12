class Solution {
    #define ll long long
public:
    int search(vector<int>& nums, int target) {
        ll s=0,e=nums.size()-1;
        ll temp=-1;
        if(nums[s]>nums[e] ) {
            while(s<=e){
                ll m=s+(e-s)/2;
                if(nums[m]>=nums[s] && nums[m]>=nums[e] && nums[m]>nums[m+1]){
                    temp=m;
                    break;
                }
                else if (nums[m]<nums[s]) e=m-1;
                else s=m+1;
            }
            if(nums[temp]>target && nums[nums.size()-1]>=target){
                s=temp+1,e=nums.size()-1;
            }
            else{
                s=0,e=temp;
            }
        }
        while(s<=e){
            ll m=s+(e-s)/2;
            if(nums[m]==target) return m;
            else if(nums[m]>target) e=m-1;
            else s=m+1;
        }
        return -1;
    }
};
