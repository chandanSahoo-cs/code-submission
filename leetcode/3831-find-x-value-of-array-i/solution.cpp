#define ll long long

class Solution {
public:
    vector<ll> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll>curr(k),prev(k);
        vector<ll>ans(k);

        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                int r = (j*(nums[i]%k))%k;
                curr[r]+=prev[j];
                ans[r]+=prev[j];
            }
            
            curr[nums[i]%k]++;
            ans[nums[i]%k]++;

            prev = curr;
            curr = vector<ll>(k);
        }

        return ans;
    }
};
