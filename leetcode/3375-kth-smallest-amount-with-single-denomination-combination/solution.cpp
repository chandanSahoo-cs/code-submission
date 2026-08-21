#define ll long long

class Solution {
public:
    vector<pair<ll,ll>>sub;

    ll lcm(ll a, ll b){
        return a*(b/__gcd(a,b));
    }

    void precompute(vector<int>&coins){
        ll n = coins.size();

        for(ll i=1;i<(1<<n);i++){
            ll cnt = 0;
            ll prod = 0;

            for(ll j=0;j<n;j++){
                if(i&(1<<j)){
                    prod = cnt==0?coins[j]:lcm(prod,(ll)coins[j]);
                    cnt++;
                }    
            }

            sub.push_back({prod,cnt});
        }

        return;
    }

    bool compute(ll m, ll k){
        ll total = 0;
        for(auto &[prod,cnt]:sub){
            if(cnt&1) total+=(m/prod);
            else total-=(m/prod);
        }

        if(total>=k) return true;
        return false;
    }

    ll findKthSmallest(vector<int>& coins, int k) {
        ll n = coins.size();

        vector<int>mark(n,1);

        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(i!=j && coins[j]%coins[i]==0 && mark[j]) mark[j]=0; 
            }
        }

        vector<int>change;

        for(int i=0;i<n;i++){
            if(mark[i]) change.push_back(coins[i]);
        }

        precompute(change);

        ll l = *min_element(change.begin(),change.end());
        ll r = k*l;

        ll ans = r;

        while(l<=r){
            ll m = l+(r-l)/2;
            if(compute(m,k)){
                ans = m;
                r = m-1;
            }else l = m+1;
        }

        return ans;
    }
};
