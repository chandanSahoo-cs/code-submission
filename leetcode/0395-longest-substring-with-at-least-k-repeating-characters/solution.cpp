class Solution {
public:

    int solve(string &s, int k, int l, int r){
        if(l>r) return 0;

        vector<int>count(26);

        for(int i=l;i<=r;i++){
            count[s[i]-'a']++;
        }

        int strt=l;
        int mx = 0;

        for(int i=l;i<=r;i++){
            if(count[s[i]-'a']<k){
                mx = max(mx,solve(s,k,strt,i-1));
                strt = i+1;
            }
        }

        if(strt==l) return r-l+1;

        mx = max(mx,solve(s,k,strt,r));

        return mx;
    }

    int longestSubstring(string s, int k) {
        return solve(s,k,0,s.size()-1);
    }
};
