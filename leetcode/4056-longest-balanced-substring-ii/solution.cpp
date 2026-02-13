class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int len = 1;
        // case 1 : all three
        int v1 = 0, v2 = 0;

        map<pair<int,int>,int>mp;
        mp[{0,0}]=-1;

        for(int i=0;i<n;i++){
            if(s[i]=='a') v1++;
            else if(s[i]=='c') v2++;
            else v1--,v2--;

            if(mp.find({v1,v2})==mp.end()){
                mp[{v1,v2}]=i;
            }
            
            len = max(len,i-mp[{v1,v2}]);
        }

        // case 2 : for only 2
        vector<string>comb = {"ab","bc","ca"};

        for(int k=0;k<3;k++){
            int v = 0;
            map<int,int>mp;
            mp[0]=-1;

            for(int i=0;i<n;i++){
                if(s[i]==comb[k][0]) v++;
                else if(s[i]==comb[k][1]) v--;
                else{
                    mp.clear();
                    v=0;
                }


                if(mp.find(v)==mp.end()){
                    mp[v]=i;
                }


                len = max(len,i-mp[v]);
            }
        }

        // case 3 : for only 1
        int cnt = 1;

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) cnt++;
            else cnt=1;

            len = max(len,cnt);
        }

        return len;
    }
};
