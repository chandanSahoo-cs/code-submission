#define ll long long

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int i = 0, j = 0;
        int mn = n-1;

        while(i<n && j<n){
            ll tr = (ll)nums[i]*k;

            while(j<n && nums[j]<=tr) j++;

            mn = min(mn,i+n-j);
            i++;
        }

        return mn;
    }
};
