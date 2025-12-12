class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,n=s.size();

        unordered_map<char,int>mp;

        int mx=0;

        while(l<n && r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            mx = max(mx,r-l+1);
            r++;
        }

        return mx;
    }
};
