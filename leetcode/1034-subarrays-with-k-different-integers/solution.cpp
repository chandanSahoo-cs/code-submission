class Solution {
public:
    int compute(vector<int>&nums, int k){
        int n = nums.size();

        unordered_map<int,int>mp;

        int l = 0, r = 0;
        int ans = 0;

        while(r<n){
            mp[nums[r]]++;

            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);

                l++;
            }
            ans+=r-l+1;
            r++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return compute(nums,k)-compute(nums,k-1);
    }
};
