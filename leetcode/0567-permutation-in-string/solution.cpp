class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size(), m = s2.size();
        vector<int>ref(26);
        vector<int>cmp(26);

        for(auto c:s1){
            ref[c-'a']++;
        }

        int l = 0, r = 0;

        while(r<m){
            cmp[s2[r]-'a']++;

            if(r-l+1==n){
                if(ref==cmp) return true;
                cmp[s2[l]-'a']--;
                l++;
            }

            r++;
        }

        return false;
    }
};
