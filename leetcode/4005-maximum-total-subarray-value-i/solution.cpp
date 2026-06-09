#define ll long long
class Solution {
public:
    ll maxTotalValue(vector<int>& nums, int k) {
        ll mx = *max_element(nums.begin(),nums.end());  
        ll mn = *min_element(nums.begin(),nums.end());

        return k*1LL*(mx-mn);  
    }
};
