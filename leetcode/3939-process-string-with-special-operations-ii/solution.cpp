#define ll long long
class Solution {
public:
    char processStr(string s, ll k) {
        ll len = 0;
        int n = s.size();

        for(auto c:s){
            if(c=='*') len = max(len-1,0LL);
            else if(c=='#') len*=2;
            else if(c!='%') len++;
        }

        if(k>=len) return '.';

        for(int i=n-1;i>=0;i--){
            if(s[i]=='*') len++;
            else if(s[i]=='#'){
                if(k>=len/2){
                    k-=(len/2);
                }
                len = len/2;
            }else if(s[i]=='%'){
                k = len-k-1;
            }else{
                if(k+1==len) return s[i];
                len--;
            }
        }

        return '.';
    }
};
