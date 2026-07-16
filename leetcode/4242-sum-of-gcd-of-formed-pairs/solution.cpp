#define ll long long

class Solution {
public:
    ll gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<ll>pref(n);
        int mx = 0;

        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            pref[i] = gcd(nums[i],mx);
        }

        sort(pref.begin(),pref.end());


        int l = 0, r = n-1;

        ll sum = 0;
        while(l<r){
            sum+=gcd(pref[l],pref[r]);
            l++,r--;
        }

        return sum;
    }
};
