const int mod = 1e9+7;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for(auto &ele:queries){
            int l = ele[0], r = ele[1], k = ele[2], v = ele[3];

            for(int i=l;i<=min(n-1,r);i+=k){
                nums[i] = (nums[i]*1LL*v)%mod;
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            ans^=nums[i];
        }

        return ans;
    }
};
