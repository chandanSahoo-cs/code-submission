#define ll long long

class Solution {
public:
    ll maxValue(vector<int>& a) {
        int n = a.size();
        vector<ll>pref(n+1,0);
        
        for(int i=0;i<n;i++){
            int val = i&1?-a[i]:a[i];
            pref[i+1] = val;
            pref[i+1] += pref[i];
        }

        ll ans = pref[n];

        vector<ll>p = {LLONG_MIN,LLONG_MIN};
        ll best = LLONG_MIN;

        for(int i=1;i<n;i++){
            int l = i-1;
            int signl = (i-1)&1?-1:1;

            for(int j=0;j<2;j++){
                int signr = j&1?-1:1;
                p[j] = max(p[j],(ll)a[l]*(signr-signl) + 2*pref[l+1]);
            }

            best = max(best,p[i&1]-2*pref[i+1]);
        }

        return ans+max(0LL,best);
    }
};

/*
max contri of l....r = 2*(sum(l+1,l+2,l+3...r) = -2*(pref[r]-pref[l])+a[l]*(sign(r)-sign(l))

-> a[l]*(sign(r)-sign(l))-2*(pref[r]-pref[l])
-> a[l]*sign(r) - a[l]*sign(l) - 2*pref[r] + 2*pref[l];
-> a[l]*(sign(r) - sign(l)) + 2*pref[l] - 2*pref[r];
*/
