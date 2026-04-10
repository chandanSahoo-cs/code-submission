class Solution {
public:
    pair<int,int> compute(string &s, int l, int r){
        int n = s.size();
        while(l>=0 && r<=n-1 && s[l]==s[r]) l--, r++;

        return {l+1,r-1};
    }

    string longestPalindrome(string s) {
        int n = s.size();

        int l=-1,r=-1,mx=0;

        for(int i=0;i<n;i++){
            auto [l1,r1] = compute(s,i,i);

            if(r1-l1+1>mx){
                mx = r1-l1+1;
                l=l1,r=r1;
            }

            if(i>0){
                auto [l2,r2] = compute(s,i-1,i);
                if(r2-l2+1>mx){
                    mx = r2-l2+1;
                    l=l2,r=r2;
                }
            }
        }

        return s.substr(l,r-l+1);
    }
};
