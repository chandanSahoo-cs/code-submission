#define ll long long

const int mod = 1e9+7;

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        ll t = k;
        ll cost = 0;
        ll times = 0;

        for(int i=0;i<n;i++){
            if(nums[i]>t){
                ll tr = nums[i]-t;
                ll inc = (tr+k-1)/k;
                ll a = times+1, l = times+inc;
                ll m = l-a+1;

                ll apl = (a+l)%mod;
                if(m&1) apl/=2;
                else m/=2;

                ll mapl = (apl*m)%mod;
                
                cost = (cost+mapl)%mod;
                t+=inc*k;
                times = l;
            }
            t-=nums[i];
        }

        return cost;
    }
};
