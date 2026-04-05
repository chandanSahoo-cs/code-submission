class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int>mp;

        for(auto ele:s){
            mp[ele]++;
        }

        int cnt = 0;
        
        for(auto ele:s){
            char c = ele;
            char m = isalpha(c)?'z'-(c-'a'):'9'-(c-'0');

            cnt+=abs(mp[c]-mp[m]);
            mp[c]=0;
            mp[m]=0;
        }

        return cnt;
    }
};
