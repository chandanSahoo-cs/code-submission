class Solution {
    #define ll long long
public:
    int findPeakElement(vector<int>& nums) {
        ll s=0,e=nums.size()-1;
        while(s<=e){
            ll m=s+(e-s)/2;
            if((m==nums.size()-1 || nums[m]>nums[m+1]) && (m==0 || nums[m]>nums[m-1])) return m;
            else if((m==0 || nums[m]>nums[m-1])) s=m+1;
            else e=m-1;
        }
        return -1;
    }
};
