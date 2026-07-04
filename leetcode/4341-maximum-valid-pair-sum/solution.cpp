class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>suff(n);

        for(int i=n-1;i>=0;i--){
            if(i==n-1) suff[i] = nums[i];
            else suff[i] = max(nums[i],suff[i+1]);
        }

        int mx = 0;
        for(int i=0;i<n-k;i++){
            mx = max(mx,nums[i]+suff[i+k]);
        }

        return mx;
    }
}; 
