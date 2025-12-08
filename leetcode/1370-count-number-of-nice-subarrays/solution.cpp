class Solution {
public:
    int give(vector<int>& nums, int k){
        int n = nums.size();
        int i=0,j=0;

        int ans=0;
        int cnt=0;

        while(j<n){
            cnt+=(nums[j]&1);

            while(cnt>k){
                cnt-=(nums[i]&1);
                i++;
            }

            ans+=j-i+1;
            j++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        return give(nums,k)-give(nums,k-1);
    }
};
