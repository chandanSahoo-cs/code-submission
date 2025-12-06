class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int>mp;

        for(auto ele:arr){
            mp[ele]++;
        }

        int cnt=0;

        for(auto [key,value]:mp){
            int ele=key;
            if(mp.find(2*ele)!=mp.end()){
                if(ele==0){
                    cnt+=mp[ele]/2;
                    mp[ele]=0;
                }else{
                    int mn = min(mp[ele],mp[2*ele]);
                    cnt+=mn;
                    mp[ele]-=mn;
                    mp[2*ele]-=mn;
                }

                cout<<ele<<" "<<cnt<<"\n";
            }
        }

        // cout<<cnt<<"\n";

        return cnt==arr.size()/2;
    }
};
