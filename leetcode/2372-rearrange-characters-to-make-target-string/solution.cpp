class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        unordered_map<char,int>curr;
        unordered_map<char,int>record;

        for(auto c:t){
            record[c]++;
        }

        for(auto c:s){
            curr[c]++;
        }

        int mn = INT_MAX;

        for(auto &[key,value]:record){
            if(curr.count(key)){
                mn = min(mn,curr[key]/value);
            }else mn = 0;
        }

        return mn;
    }
};
