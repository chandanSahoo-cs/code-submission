#define ll long long

class Solution {
public:
    void countSort(vector<int>&nums){
        int mx = *max_element(nums.begin(),nums.end());

        vector<int>freq(mx+1);

        for(auto ele:nums) freq[ele]++;

        int j=0;

        for(int i=0;i<=mx;i++){
            while(freq[i]--){
                nums[j++]=i;
            }
        }

        return;
    }

    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        countSort(nums);

        int l = 0, r = 0;
        int ans = 0;

        ll sum = 0;

        while(r<n){
            sum+=nums[r];

            while((r-l+1)*1LL*nums[r]-sum>k){
                sum-=nums[l];
                l++;
            }

            ans = max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};
