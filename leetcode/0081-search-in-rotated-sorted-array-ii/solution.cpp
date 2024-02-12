class Solution {
    #define ll long long
public:
    bool search(vector<int>& nums, int target) {
        set<int>num1={nums.begin(),nums.end()};
        nums={num1.begin(),num1.end()};
        ll s=0,e=nums.size()-1;
        ll temp=-1;
        if(nums[s]>=nums[e] && nums.size()!=1) {
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
            if(nums[m]==target) return true;
            else if(nums[m]>target) e=m-1;
            else s=m+1;
        }
        return false;
    }
};
