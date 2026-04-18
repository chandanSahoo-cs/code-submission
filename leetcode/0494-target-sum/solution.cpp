class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if((sum+target)&1) return 0;
        int t = (sum+target)>>1;

        if(t<0) return 0;

        vector<int>curr(t+1),next(t+1);
        next[0]=1;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=t;j++){
                int ans = 0;
                if(j-nums[i]>=0){
                  ans += next[j-nums[i]];  
                }
                ans+=next[j];
                curr[j] = ans;
            }
            next = curr;
        }  

        return next[t];
    }
};
