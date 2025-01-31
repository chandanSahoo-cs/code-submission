#define ll long long

class Solution {
public:
    ll check(vector<int>&a,ll n,ll m){
        ll hours = 0;
        for(ll i=0;i<n;i++){
            hours+=(a[i]+m-1)/m;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ll mx = *max_element(piles.begin(),piles.end());
        ll n = piles.size();
        ll s=1,e=mx;
        ll ans = LLONG_MAX;
        while(s<=e){
            ll m = s+(e-s)/2;
            ll hours = check(piles,n,m);
            cout<<m<<" "<<hours<<"\n";
            if(hours<=h){
                e=m-1;
                ans = min(m,ans);
            }
            else{
                s=m+1;
            }
        }

        return ans;
    }
};
