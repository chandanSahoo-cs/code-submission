#define ll long long

class Solution {
public:
    ll compute(int a, int b){
        ll gcd = __gcd(a,b);
        return (a*1LL*b)/(gcd*gcd);
    }

    ll maxPairStrength(vector<int>& nums) {
        int n = nums.size();

        ll mx = 0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mx = max(mx,compute(nums[i],nums[j]));
            }
        }

        return mx;
    }
};
