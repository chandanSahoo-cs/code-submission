class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();

        vector<int>alpha(26,0);

        int l = 0, r = 0;
        int mx = 0;

        while(r<n){
            alpha[s[r]-'a']++;

            while(l<r && alpha[s[r]-'a']>2){
                alpha[s[l]-'a']--;
                l++;
            }

            mx = max(mx, r-l+1);
            r++;
        }

        return mx;
    }
};
