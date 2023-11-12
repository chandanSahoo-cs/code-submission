class Solution {
public:
    // bool jumpCheck(int i,int val,vector<int>&nums){
    //     for(int j=1;j<=val;j++){
    //         if(i+j==nums.size()-1){
    //             return true;
    //         }
    //         else{
    //             if(jumpCheck(i+j,nums[i+j],nums)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    // bool canJump(vector<int>& nums) {
    //     if(nums.size()==1) return true;
    //     if(nums[0]==nums.size()-1){
    //         return true;
    //     }
    //     else{
    //         return (jumpCheck(0,nums[0],nums));
    //     }
    // }
    bool canJump(std::vector<int>& nums) {
        int maxReachable = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i > maxReachable) return false;
            maxReachable =max(maxReachable, i + nums[i]);
            if (maxReachable >= n - 1) return true;
        }
        return false;
    }
};
