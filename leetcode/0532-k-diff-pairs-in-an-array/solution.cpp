class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(auto ele:nums) mp[ele]++;

        int cnt=0;
        for(auto [key,value]:mp){
            int tr = k+key;
            
            int fn=0;

            if(mp.find(tr)!=mp.end()){
                if(tr==key && mp[tr]>1) fn=1;
                else if(tr!=key) fn=1;
            }

            cnt+=fn;
        }

        return cnt;
    }
};
