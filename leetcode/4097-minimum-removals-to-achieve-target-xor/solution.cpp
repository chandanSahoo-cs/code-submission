
class Solution {
public:
    int dp[45][1<<14];
    
    int rec(vector<int>&nums , int tr, int i,int val){
        int n = nums.size();

        if(i==n){
            if(val!=tr) return 41;
            return 0;
        }

        if(dp[i][val]!=-1) return dp[i][val];

        int cnt = min(rec(nums,tr,i+1,val^nums[i]),1+rec(nums,tr,i+1,val));

        return dp[i][val]=cnt;
    }
    
    int minRemovals(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));

        int ans = rec(nums,target,0,0);

        return ans>40?-1:ans;
    }
};
