#define ll long long

class Solution {
public:
    ll minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();

        vector<ll>aval(n+1);

        for(auto &ele:boosts){
            int l = ele[0], r = ele[1], v = ele[2];
            aval[l] += v;
            aval[r+1] -= v;
        }

        for(int i=1;i<n;i++){
            aval[i]+=aval[i-1];
        }

        ll total = 0;
        ll req = 0;

        for(int i=0;i<n;i++){
            ll extra = max(0LL,monsters[i]-aval[i]);
            if(extra>0){
                req = total+extra;
            }
            total+=monsters[i];  
        }

        return req;
    }
};
