class Solution {
public:
    int give(int n, vector<int>&nums, int k){
        if(k<0) return 0;
        unordered_map<int,int>mp;
        int l=0,r=0,ans=0;
        while(r<n){
            // if(mp.find(nums[r])==mp.end()){
            // }
            mp[nums[r]]++;
            // else mp[nums[r]]++;

            while(mp.size()>k){
                mp[nums[l]]--;
                if(!mp[nums[l]]){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans+=r-l+1;
            cout<<ans<<" ";
            r++;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return give(n,nums,k)-give(n,nums,k-1);
    }
};
