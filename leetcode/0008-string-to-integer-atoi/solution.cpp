#define ll long long

class Solution {
public:

    ll num(string &s, ll i, ll sign , bool digit, ll ans, ll signF, ll mx,ll mn){
        if(i==s.size()) return ans*sign;
        if(!digit && !signF){
            if(!isdigit(s[i]) && s[i]!='-' && s[i]!='+' && s[i]!=' ') return ans*sign;
        }
        else{
            if(!isdigit(s[i])) return ans*sign;
        }

        if(!isdigit(s[i])){
            if(s[i]=='-'){
                sign = -1;
                signF = true;
            }
            else if(s[i]=='+'){
                signF=true;
            }
        }
        else{
            digit = true;
            ans*=10;
            ans+=s[i]-'0';
        }

        if(ans*sign>mx) return mx;
        else if(ans*sign<mn) return mn;

        return num(s,++i,sign,digit,ans,signF,mx,mn);
    }

    int  myAtoi(string s) {
        string s1 = s;
        ll mx = pow(2,31);
        ll mn = -mx;
        mx-=1;
        ll ans = num(s1,0,1,false,0,false,mx,mn);
        return ans;
    }
};
