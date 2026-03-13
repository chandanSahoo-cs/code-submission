#define ll long long

class Solution {
public:
    int giveX(ll sum){
        return (-1+sqrt(1+8*sum))/2;
    }

    ll solve(vector<int>&wt, ll t,ll mh){

        ll sum = 0;

        for(auto ele:wt){
            sum+=giveX(t/ele);
            if(sum>=mh) break;
        }

        return sum;
    }

    ll minNumberOfSeconds(int mh, vector<int>& wt) {

        ll l = 1;
        ll r = 1e18;

        ll ans = r;

        while(l<=r){
            ll m = l+(r-l)/2;

            if(solve(wt,m,mh)<mh) l = m+1;
            else{
                ans=m;
                r=m-1;
            }
        }

        return ans;
    }
};
