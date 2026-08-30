class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mnL = min_element(nums.begin(),nums.end())-nums.begin()+1;
        int mnR = n-mnL+1;

        int mxL = max_element(nums.begin(),nums.end())-nums.begin()+1;
        int mxR = n-mxL+1;

        int ans = min(max(mnL,mxL),max(mnR, mxR));

        ans = min(ans,mnL+mxR);
        ans = min(ans,mxL+mnR);

        return ans;
    }
};
