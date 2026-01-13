class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char,int>mp;

        for(auto &c:s){
            mp[c]++;
        }

        vector<vector<char>>bucket(n+1);

        for(auto &[key,freq]:mp){
            bucket[freq].push_back(key);
        }

        string ans="";
        for(int i=n;i>=1;i--){
            for(auto c:bucket[i]){
                for(int j=0;j<i;j++){
                    ans.push_back(c);
                }
            }
        }

        return ans;
    }
};
