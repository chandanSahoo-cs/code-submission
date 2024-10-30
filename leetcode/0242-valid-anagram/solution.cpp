class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        map<int ,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        for(int i=0;i<m;i++){
            mp[t[i]]--;
            if(mp[t[i]]<0) return false;
        }
        for(auto ele:mp){
            if(ele.second!=0) return false;
        }
        return true;
    }
};
