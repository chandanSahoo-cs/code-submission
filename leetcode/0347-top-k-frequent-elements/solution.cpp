class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(auto ele:nums){
            mp[ele]++;
        }

        vector<vector<int>>buckets(n+1);

        for(auto &[key,freq]:mp){
            buckets[freq].push_back(key);
        }

        vector<int>ans;

        int f=n;

        while(ans.size()<k){
            for(auto &ele:buckets[f--]){
                ans.push_back(ele);
                if(ans.size()==k) break;
            }
        }

        return ans;
    }
};
