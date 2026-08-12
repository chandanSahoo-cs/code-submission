class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;

        int l = 0, r = 0;
        int mx = 0;

        while(r<n){
            mp[nums[r]]++;

            while(l<=r && mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }

            mx = max(mx,r-l+1);
            r++;
        }

        return mx;
    }
};
