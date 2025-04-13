class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(auto ele:nums){
            mp[ele]++;
        }

        // struct cmp{
        //     bool operator()(int i,int j){
        //         return mp[i]>mp[j];
        //     }
        // }

        auto cmp = [&](int i,int j){
            return mp[i]>mp[j];
        };

        priority_queue<int,vector<int>,decltype(cmp)>pq(cmp);

        for(auto [key,value]:mp){
            pq.push(key);
            if(pq.size()>k){
                pq.pop();
            }
        };

        

        vector<int>ans;

        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;

        
    }   
};
