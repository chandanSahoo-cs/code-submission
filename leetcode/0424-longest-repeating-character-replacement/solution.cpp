class Solution {
public:
    int give(vector<int>&a){
        return accumulate(a.begin(),a.end(),0)-(*max_element(a.begin(),a.end()));
    }

    int characterReplacement(string s, int k) {
        int n = s.size();

        int l=0,r=0;
        int ans=0;
        vector<int>ch(26,0);

        int mx=0;

        // ch[s[0]-'A']++;
        while(r<n){
            ch[s[r]-'A']++;
            mx =  max(mx,ch[s[r]-'A']);
            if((r-l+1)-mx<=k){
                ans = max(ans,r-l+1);
            }
            else{
                ch[s[l]-'A']--;
                l++;
            }
            r++;
        }

        return ans;
    }
};
