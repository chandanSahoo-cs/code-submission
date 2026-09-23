class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);

        int l = 0, r = 0;
        int sum = 0;

        int ans = INT_MAX;

        while(r<n){
            sum+=nums[r];

            while(l<=r && total-sum<x){
                sum-=nums[l];
                l++;
            }

            if(total-sum==x){
                ans = min(ans,n-(r-l+1));
            }
            r++;
        }

        return ans==INT_MAX?-1:ans;
    }
};
