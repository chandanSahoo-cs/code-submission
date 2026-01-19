class Solution {
public:
    pair<int,int> givePalindrome(string &s, int l, int r){
        int n = s.size();

        while(l>=0 && r<n && s[l]==s[r]){
            l--;
            r++;
        }
        l++;
        r--;

        return {l,r};
    }

    string longestPalindrome(string s) {
       int n = s.size();

       int l=0,r=0;
       int mx = 1;

       for(int i=0;i<n;i++){
            auto [l1,r1] = givePalindrome(s,i,i);
            if(r1-l1+1>mx){
                mx = max(mx,r1-l1+1);
                l=l1,r=r1;
            }

            if(i!=0){
                auto [l2,r2] = givePalindrome(s,i,i-1);
                if(r2-l2+1>mx){
                    mx = max(mx,r2-l2+1);
                    l=l2,r=r2;
                }
            }
       }

       return s.substr(l,r-l+1); 
    }
};
