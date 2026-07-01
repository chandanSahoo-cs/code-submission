class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size(), m = s.size();
        
        vector<int>ref(26);
        vector<int>cmp(26);

        for(auto c:p){
            ref[c-'a']++;
        }

        int l = 0, r = 0;

        vector<int>ans;

        while(r<m){
            cmp[s[r]-'a']++;

            if(r-l+1==n){
                if(ref==cmp)ans.push_back(r-n+1);
                cmp[s[l]-'a']--;
                l++;
            }

            r++;
        }

        return ans;
    }
};
