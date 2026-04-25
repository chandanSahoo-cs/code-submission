#define ll long long
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());

        ll asc = 0, desc = 0;

        int l = 0, r = n-1;

        while(nums[l]<mx){
            asc+=nums[l++];
        }

        while(nums[r]<mx){
            desc+=nums[r--];
        }

        if(asc>desc) return 0;
        else if(asc<desc) return 1;
        return -1;
    }
};
