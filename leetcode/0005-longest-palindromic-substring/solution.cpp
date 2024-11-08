class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans(1,s[0]);
        for(int i=0;i<n-1;i++){
            //For even
            int l = i;
            int r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            l++;
            r--;
            if(l>=0 && r<n && ans.size()<r-l+1){
                ans = s.substr(l,r-l+1);
            }

            //For odd
            l=i-1;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            l++;
            r--;
            if(l>=0 && r<n && ans.size()<r-l+1){
                ans=s.substr(l,r-l+1);
            }
        }
        return ans;
    }
};
