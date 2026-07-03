class Solution {
public:

    int freq(vector<int>&alpha){
        int mx = 0;
        for(auto ele:alpha){
            mx = max(mx,ele);
        }

        return mx;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();

        vector<int>alpha(26);

        int l = 0, r = 0;
        int mxFreq = 0;

        int ans = 0;

        while(r<n){
            alpha[s[r]-'A']++;
            mxFreq = freq(alpha);

            while(r-l+1-mxFreq>k){
                alpha[s[l]-'A']--;
                l++;
                mxFreq = freq(alpha);
            }

            ans = max(r-l+1,ans);
            r++;
        }

        return ans;
    }
};
