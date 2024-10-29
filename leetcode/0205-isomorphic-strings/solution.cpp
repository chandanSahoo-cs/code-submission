class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<int, int>mp;
        int n = s.size();
        map<int,int>mark;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end() && !mark[t[i]]){
                mp[s[i]] = t[i];
                mark[t[i]] = 1;
            }
            else{
                if(mp[s[i]]!=t[i]) return false;
            }
        }

        return true;       
    }
};
