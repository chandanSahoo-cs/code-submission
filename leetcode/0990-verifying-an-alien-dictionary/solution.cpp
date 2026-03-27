class Solution {
public:
    bool isAlienSorted(vector<string>& word, string order) {
        unordered_map<char,int>mp;

        for(int i=0;i<26;i++){
            mp[order[i]]=i;
        }

        for(int i=0;i<word.size()-1;i++){
            int k = 0;

            while(k<word[i].size() && k<word[i+1].size() && word[i][k]==word[i+1][k]) k++;

            if(k==word[i+1].size() && k<word[i].size()) return false;

            if(k<word[i].size() && k<word[i+1].size()){
                if(mp[word[i][k]]>mp[word[i+1][k]]) return false;
            }

        }

        return true;
    }
};
