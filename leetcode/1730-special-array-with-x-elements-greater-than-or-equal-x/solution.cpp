class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sz=nums.size();
        while(sz>0){
            int s=0,e=nums.size()-1;
            while(s<=e){
                int m=s+(e-s)/2;
                if(nums[m]<sz) s=m+1;
                else e=m-1;
            }
            if(nums.size()-s==sz) return sz;
            sz--;
        }
        return -1;
    }
};
