class Solution {
    #define ll long long
public:
    int minOperations(vector<int>& nums, int k) {
        ll cnt=0;
        for(ll i=0;i<nums.size();i++){
            if(nums[i]<k) cnt++;
        }
        return cnt;
    }
};
