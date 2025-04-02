class Solution {
public:
    bool check(vector<int>&ch){
        for(auto ele:ch){
            if(ele>1){
                return false;
            }
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int>ch(128,0);
        int l=0,r=0;
        int ans=0;
        ch[s[r]-'\0']++;
        while(r<n){
            if(ch[s[r]-'\0']<2){
                r++;
                ch[s[r]-'\0']++;
                ans = max(r-l,ans);
            }
            else{
                ch[s[l]-'\0']--;
                l++;
            }
        }

        return ans;
    }
};
