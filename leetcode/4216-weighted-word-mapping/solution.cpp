class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for(auto &word:words){
            int sum = 0;
            for(auto c:word){
                sum+=weights[c-'a'];
            }
            int res = sum%26;
            ans+=('a'+26-res-1);
        }

        return ans;
    }
};
