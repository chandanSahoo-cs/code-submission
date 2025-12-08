class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(auto ele:nums){
            mp[ele]++;
        }

        int cnt=0;

        for(auto [key,value]:mp){
            int tr = k+key;

            if(mp.find(tr)!=mp.end()){
                int fn = 1;
                if(tr==key && value<=1){
                    fn = 0;
                }

                cnt+=fn;
            }
        }

        return cnt;
    }
};
