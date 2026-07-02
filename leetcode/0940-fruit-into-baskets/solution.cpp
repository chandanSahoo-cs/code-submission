class Solution {
public:
    int totalFruit(vector<int>& nums) {

        int n = nums.size();

        int l = 0, r = 0;

        int mx = 0;

        unordered_map<int,int>mp;

        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>2){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }

            mx = max(mx,r-l+1);
            r++;
        }

        return mx;
    }
};
