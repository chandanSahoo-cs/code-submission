class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;

        string t = "balloon";

        for(auto c:t){
            mp[c] = 0;
        }

        for(auto c:text){
            if(mp.count(c)){
                mp[c]++;
            }
        }

        int mn = INT_MAX;
        for(auto &[key,value]:mp){
            if(key=='l' || key=='o'){
                mn = min(mn,value/2);
            }else mn = min(mn,value);
        }

        return mn;
    }
};
