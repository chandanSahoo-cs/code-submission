class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;

        for(auto ele:time){
            mp[ele%60]++;
        }

        int cnt=0;

        for(auto ele:time){
            int tr = (60-(ele%60))%60;
            mp[ele%60]--;
            if(mp.find(tr)!=mp.end()){
                cnt+=mp[tr];
            }
        }

        return cnt;
    }
};
