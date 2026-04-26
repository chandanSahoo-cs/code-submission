class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    
    string sortVowels(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        unordered_map<char,int>occur;

        for(auto &ele:s) mp[ele]++;

        vector<int>foo;

        for(int i=0;i<n;i++){
            if(isVowel(s[i])) foo.push_back(i);
            if(!occur.count(s[i])) occur[s[i]] = i;
        }

        sort(foo.begin(),foo.end(),[&](int i, int j){
            if(mp[s[i]]==mp[s[j]]){
                return occur[s[i]]<occur[s[j]];
            }
           return mp[s[i]]>mp[s[j]]; 
        });

        int m = foo.size();
        int j=0;

        string ans = "";
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                ans += s[foo[j]];
                j++;
            }else ans+=s[i];
        }

        return ans;
    }
};
