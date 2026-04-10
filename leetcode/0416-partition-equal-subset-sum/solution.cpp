class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;

        vector<bool>curr(sum+1),next(sum+1);
        next[sum/2]=true;

        int n = nums.size();

        for(int i=n-1;i>=0;i--){
            for(int j=sum/2;j>=0;j--){
                curr[j] = next[j] || (j+nums[i]<=sum/2 && next[j+nums[i]]);
            }

            next = curr;
        }

        return next[0];
    }
};
