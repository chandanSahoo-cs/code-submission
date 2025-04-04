class Solution {
public:
    int give(int n, vector<int>&nums, int k){
        int l=0,r=0,cnt=0;
        long long ans=0;
        if(k<0) return 0; 
        while(r<n){
            if(nums[r]&1) cnt++;
            while(cnt>k){
                if(nums[l]&1) cnt--;
                l++;
            }
            ans+=r-l+1;
            r++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        return give(n,nums,k)-give(n,nums,k-1);
    }
};
