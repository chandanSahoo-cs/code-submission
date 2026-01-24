class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();

        vector<int>freq(1e5+1,0);

        for(auto ele:nums){
            freq[ele]++;
        }

        int mx = INT_MIN;
        int l = 1, r = 1e5;

        while(l<=r){
            while(l<=r && freq[l]==0) l++;
            while(l<=r && freq[r]==0) r--;

            if(l>r) break;
            
            mx = max(mx,l+r);
            freq[l]--;
            freq[r]--;
        }

        return mx;
    }

    // 2 3 4 4 5 6
};
