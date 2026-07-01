#define ll long long
class Solution {
public:
    ll maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0, r = 0;

        unordered_map<int,int>mp;

        ll sum = 0;
        ll mx = 0;

        while(r<n){
            sum+=nums[r];
            mp[nums[r]]++;

            if(r-l+1==k){

                if(mp.size()==k){
                    mx = max(mx,sum);
                }

                sum-=nums[l];

                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);

                l++;
            }
            
            r++;
        }

        return mx;
    }
};
