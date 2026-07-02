#define ll long long

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0, r = 0;

        int cnt=0;

        ll curr = 1;

        while(r<n){
            curr*=nums[r];

            while(curr>=k){
                curr/=nums[l];
                l++;
            }

            cnt+=r-l+1;
            r++;
        }

        return cnt;
    }
};
