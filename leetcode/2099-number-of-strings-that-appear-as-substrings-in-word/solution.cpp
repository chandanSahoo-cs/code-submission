class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();

        unordered_map<string,int>mp;

        for(auto &ele:patterns) mp[ele]++;

        int cnt = 0;

        for(int i=0;i<n;i++){
            string s = "";
            for(int j=i;j<n;j++){
                s+=word[j];
                if(mp.count(s)){
                    cnt+=mp[s];
                    mp.erase(s);
                }
            }
        }

        return cnt;  
    }
};
