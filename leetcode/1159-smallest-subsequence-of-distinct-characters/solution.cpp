class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        vector<int>freq(26,0);

        for(auto c:s) freq[c-'a']++;
        unordered_set<char>st;

        string t = "";

        for(int i=0;i<n;i++){
            freq[s[i]-'a']--;

            if(st.count(s[i])) continue;

            while(!t.empty() && t.back()>s[i] && freq[t.back()-'a']){
                st.erase(t.back());
                t.pop_back();
            }

            st.insert(s[i]);
            t+=s[i];
        }

        return t;
    }
};
