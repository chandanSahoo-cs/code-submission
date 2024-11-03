#define ll long long int
class Solution {
public:
    int myAtoi(string s) {
        ll n = s.size();
        bool num = false;
        bool actNum = false;
        bool sign = true;
        bool toggle = false;
        ll ans = 0;
        ll pwr = pow(2,31);

        for(ll i=0;i<n;i++){
            if(!num){
                if(s[i]==' ' && !toggle) continue;
                else if(s[i]=='-' && !toggle) sign=false,toggle = true;
                else if(s[i]=='+' && !toggle) sign=true,toggle = true;
                else if(isdigit(s[i])){
                    ans+=s[i]-'0';
                    num=true;
                }
                else break;
            }
            else{
                if(isdigit(s[i])){
                    if(s[i]=='0' && ans==0 ) continue;
                    ans*=10;
                    ans+=s[i]-'0';
                    if(ans>=pwr) break;
                }
                else break;
            }
        }
        if(!sign){
            ans = -ans;
        }
        if(ans>pwr-1){
            ans = pwr-1;
        }
        else if(ans<-pwr){
            ans = -pwr;
        }
        return ans;
    }
};
