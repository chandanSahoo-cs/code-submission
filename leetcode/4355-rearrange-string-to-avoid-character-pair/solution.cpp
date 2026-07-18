class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<char,int>mp;

        for(auto &c:s) mp[c]++;

        string t = "";
        int cnt = mp[y];
        while(cnt){
            t+=y;
            cnt--;
        }
        mp[y]=0;

        for(auto &[key,value]:mp){
            int cnt = value;
            while(cnt){
                t+=key;
                cnt--;
            }
        }

        return t;
    }
};
