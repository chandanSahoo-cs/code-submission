#define ll long long

class Solution {
public:
const int base = 31;
const int mod = 1e9+7;

bool rabinKarp(string &s, string &p){
    int n = s.size();
    int m = p.size();

    vector<ll>power(n);

    power[0]=1;

    for(int i=1;i<n;i++){
        power[i]=(power[i-1]*base)%mod;
    }

    ll pattHash = 0;

    for(int i=0;i<m;i++){
        pattHash = (pattHash+(p[i]-'a'+1)*power[i])%mod;
    }

    vector<ll>cmpHash(n+1);

    for(int i=1;i<=n;i++){
        cmpHash[i]=(cmpHash[i-1]+(s[i-1]-'a'+1)*power[i-1])%mod;
    }

    for(int i=0;i+m-1<n;i++){
        ll hash = (cmpHash[i+m]-cmpHash[i]+mod)%mod;

        if(hash==(pattHash*power[i])%mod){
            bool match = true;
            for(int j=i;j<i+m;j++){
                if(s[j]!=p[j-i]){
                    match = false;
                    break;
                }
            }

            if(match) return true;
        }
    }

    return false;
}

    int repeatedStringMatch(string a, string b) {
        
        string s = a;
        int cnt = 1;

        while(s.size()<b.size()){
            s+=a;
            cnt++;
        }

        if(rabinKarp(s,b)){
            return cnt;
        }

        s+=a;

        if(rabinKarp(s,b)){
            return cnt+1;
        }

        return -1;
    }
};
