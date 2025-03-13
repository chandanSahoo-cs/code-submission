#define ll long long
class Solution {
public:
    const int mod = 1000000007;


    ll binExpMod(ll base, ll exp) {
        ll result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    ll modMul(ll n,ll m){
        return (n*m)%mod;
    }

    ll fact(ll n){
        ll ans = 1;
        for(int i=1;i<=n;i++){
            ans = modMul(ans,i);
        }

        return ans;
    }

    ll invFact(ll n){
        return binExpMod(fact(n),mod-2)%mod;
    }


    int countAnagrams(string s) {
        vector<string>word; 

        int n = s.size();
        int f=0;

        ll ans = 1;

        for(int i=0;i<n;i++){
            if(s[i]==' '){
                word.push_back(s.substr(f,i-f));
                f=i+1;
            }
        }
        word.push_back(s.substr(f));


        vector<int>ch(26,0);

        for(int i=0;i<word.size();i++){
            int m = word[i].size();
            int j=0;
            while(j<m){
                if(word[i][j]!=' ') ch[word[i][j]-'a']++;
                else m--;
                j++;
            }
            ans = modMul(ans,fact(m));
            for(int i=0;i<26;i++){
                if(ch[i]) ans = modMul(invFact(ch[i]),ans);
            }
            ch.assign(ch.size(),0);
        }

        return ans;
    }
};
