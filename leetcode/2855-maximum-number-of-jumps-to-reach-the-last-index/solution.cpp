class Solution {
public:

    int maximumJumps(vector<int>& nums, int trg) {
        int n = nums.size();

        vector<int>dp(n+1);
        dp[n-1] = 0;

        for(int i=n-2;i>=0;i--){
            int mx = -1;
            for(int j=i+1;j<n;j++){
                int diff = nums[i]-nums[j];

                if(diff>=-trg && diff<=trg){
                    int val = dp[j];
                    if(val!=-1){
                        mx = max(mx,1+val);
                    }
                }
            }
            dp[i] = mx;
        }


        return dp[0];
    }
};
