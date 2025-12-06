class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;
        
        int n = time.size();

        for(int i=0;i<n;i++){
            int tr = time[i]%60;
            if(mp.find(tr)==mp.end()){
                mp[tr]=1;
            }else mp[tr]++;
        }


        int cnt=0;

        for(int i=0;i<n;i++){
            int tr = (60-(time[i]%60))%60;
            int cn = time[i]%60;

            if(mp.find(tr)!=mp.end()){
                mp[cn]--;
                cnt+=mp[tr];

                // cout<<cn<<" "<<tr<<"\n";
            }
        }

        return cnt;
    }
};
