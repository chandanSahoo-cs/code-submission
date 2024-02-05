class Solution {
    #define ll long long
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool check =false;
        int mnIndx=-1;
        int mxIndx=-1;
        ll s=0,e=nums.size()-1;
        while(s<=e){
            ll m=s+(e-s)/2;
            if(nums[m]==target){
                check=true;
                break;
            }
            else if(nums[m]<target) s=m+1;
            else e=m-1;
        }
        if(check){
            ll s1=0,e1=nums.size()-1;
            while(s1<=e1){
                ll m1=s1+(e1-s1)/2;
                if(nums[m1]>=target) e1=m1-1;
                else s1=m1+1;
            }
            mnIndx=s1;
            ll s2=0,e2=nums.size()-1;
            while(s2<=e2){
                ll m2=s2+(e2-s2)/2;
                if(nums[m2]<=target) s2=m2+1;
                else e2=m2-1;
            }
            mxIndx=e2;
        }
        return {mnIndx,mxIndx};
    }
};
