#define ll long long
const int mod = 1e9+7;

class Solution {
public:

    ll binExp(ll base, ll exp){
        ll ans = 1;

        while(exp){
            if(exp&1){
                ans = (ans*base)%mod;
            }
            base = (base*base)%mod;
            exp>>=1;
        }

        return ans;
    }

    int pow10[100001];
    void compute(int n){
        pow10[0]=1;

        for(int i=1;i<n;i++){
            pow10[i] = (pow10[i-1]*10LL)%mod;
        }

        return;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int>pref(n+1);
        vector<int>suff(n+1);
        vector<int>pwr(n+1);
        compute(n+1);

        for(int i=0;i<n;i++){
            int val = s[i]-'0';
            pref[i+1]=(val+pref[i])%mod;
        }

        int p=0;
        for(int i=n-1;i>=0;i--){
            int val = s[i]-'0';
            if(val==0){
                suff[i] = suff[i+1];
                pwr[i] = pwr[i+1];
            }else {
                suff[i] = (suff[i+1]+(val*1LL*pow10[p])%mod)%mod;
                pwr[i] = p;
                p++;
            }
        }

        int curr = 0;
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                curr = pwr[i];
            }else pwr[i]=curr;
        }

        vector<int>ans;

        for(auto &ele:queries){
            int l = ele[0], r = ele[1];
            
            int sum = (pref[r+1]-pref[l]+mod)%mod;
            int digit = (((suff[l]-suff[r+1]+mod)%mod)*1LL*binExp(pow10[pwr[r]],mod-2))%mod;


            int val = (sum*1LL*digit)%mod;

            ans.push_back(val); 
        }

        return ans;
    }
};
