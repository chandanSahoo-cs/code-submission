class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for(auto ele:nums){
            cnt+=(ele==0);
        }

        int tot = cnt;

        for(int i=n-1;i>=0;i--){
            if(cnt==0) break;
            if(nums[i]==0){
                tot--;
            }
            cnt--;
        }

        return tot;
    }
};
