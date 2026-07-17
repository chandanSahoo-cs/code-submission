#define ll long long

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<ll>& queries) {
        int mx = *max_element(nums.begin(),nums.end());

        vector<ll>freq(mx+1);

        for(auto ele:nums) freq[ele]++;

        vector<ll>GCD(mx+1,0);

        for(int i=mx;i>=1;i--){
            ll n = 0;
            ll overlaps = 0;

            int j = i;
            while(j<=mx){
                n+=freq[j];
                overlaps+=GCD[j];
                j+=i;
            }
            GCD[i] = (n*(n-1))/2-overlaps;
        }

        for(int i=1;i<=mx;i++){
            GCD[i]+=GCD[i-1];
        }

        vector<int>res;

        for(auto ele:queries){
            ll l = 1, r = mx+1;
            ll ans = r;

            while(l<=r){
                ll m = l+(r-l)/2;

                if(GCD[m]>=ele+1){
                    ans = m;
                    r = m-1;
                }else l = m+1;
            }

            res.push_back(ans);
        }

        return res;
    }
};
