class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int cnt = 0;

        for(auto ele:nums){
            ans^=ele;
            cnt+=ele==0;
        }

        if(cnt==n) return 0;

        if(ans==0) return n-1;

        return n;
    }
};
