class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis(n,1e9);

        for(int i=0;i<n;i++){
            int ind = lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
            lis[ind] = nums[i];
        }

        int len=0;

        for(int i=0;i<n && lis[i]<1e9;i++){
            len=i;
        }

        return len+1;
    }
};
