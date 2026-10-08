class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        string ans = "";
        int cnt = 0;

        int l = 0, r = 0;

        while(r<n){
            cnt+=s[r]=='('?1:-1;
            if(cnt>=1){
                if(cnt>1){
                    ans+=s[r];
                }else{
                    if(s[r]==')') ans+=s[r];
                }
            }
            r++;
        }

        return ans;
    }
};
