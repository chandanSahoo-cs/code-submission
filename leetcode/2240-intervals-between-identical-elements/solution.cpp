#define ll long long
class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        ll n = nums.size();

        unordered_map<int,vector<ll>>mp;
        vector<int>ind(n);

        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                ind[i] = mp[nums[i]].size();
            }else{
                ind[i] = 0;
            }

            mp[nums[i]].push_back(i);
        }

        for( auto &[key,value]:mp){
            for(int i=1;i<value.size();i++){
                value[i]+=value[i-1];
            }
        }

        vector<ll>ans(n);

        for(int i=0;i<n;i++){
            ll idx = ind[i];
            ll m = mp[nums[i]].size();

            ll left = idx>0?mp[nums[i]][idx-1]:0;
            ll right = mp[nums[i]][m-1]-mp[nums[i]][idx];

            ans[i] = ((idx<<1)-m+1)*i-left+right;
        }
        // idx*i - (m-1-idx)*i
        // (idx-(m-1-idx))*i
        // (idx-m+1+idx)*i
        // (idx*2-m+1)
        return ans;
    }
};
