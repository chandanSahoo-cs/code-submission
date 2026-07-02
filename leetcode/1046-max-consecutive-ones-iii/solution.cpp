class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0, r = 0;
        int currK = k;

        int mx = 0;

        while(r<n){

            if(nums[r]==0){
                if(currK==0){
                    while(currK==0){
                        currK+=(nums[l]==0);
                        l++;
                    }
                }
                currK--;
            }

            mx = max(r-l+1,mx);
            r++;
        }

        return mx;
    }
};
