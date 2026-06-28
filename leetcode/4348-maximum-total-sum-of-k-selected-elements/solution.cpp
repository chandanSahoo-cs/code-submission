#define ll long long

class Solution {
public:
    ll maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater());

        ll ans = 0;
        for(int i=0;i<k;i++){
            if(mul>0){
                ans += nums[i]*1LL*mul;
            }else ans+=nums[i];
            mul--;
        }

        return ans;
    }
};
