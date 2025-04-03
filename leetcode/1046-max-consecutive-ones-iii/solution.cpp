class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0;
        int ans=0;
        while(r<n){
            if(k<0){
                if(nums[l]==0){
                    k++;
                }
                else{
                }
                l++;
            }
            else{
                if(nums[r]==0) k--;
                r++;
            }
            if(k>=0) ans = max(r-l,ans);
        }
        return ans;
    }
};
