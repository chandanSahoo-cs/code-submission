class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char,int>mp;

        int i=0,j=0;
        int mx = 0;

        while(i<n && j<n){
            
            if(mp[s[j]]==0){
                mp[s[j]]++;
                j++;
            }
            else{
                mp[s[i]]--;
                i++;
            }
            mx = max(mx,j-i);
        }

        return mx;
    }
};
