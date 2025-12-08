class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int>mp;

        for(auto ele:arr) mp[ele]++;

        int cnt=0;

        for(auto [key,value]:mp){
            if(mp.find(2*key)==mp.end()) continue;
            
            int mn = min(value,mp[2*key]);
            if(key==0){
                mn/=2;
            }
            cnt+=mn;
            mp[key]-=mn;
            mp[2*key]-=mn;
        }

        return cnt==arr.size()/2;
    }
};
