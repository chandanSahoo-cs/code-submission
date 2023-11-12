class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // k%=nums.size();
        // vector<int>ans(nums.size());
        // for(int i=0;i<nums.size()-k;i++){
        //     ans[i+k]=nums[i];
        // }
        // for(int i=0;i<k;i++){
        //     ans[i]=nums[nums.size()-k+i];
        // }
        // nums=ans;
        // return;
        k%=nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());    
    }
};
