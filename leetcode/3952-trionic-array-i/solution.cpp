class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) return false;
        }

        int p = 0;

        for(int i=1;i<n-1;i++){
            if(nums[i-1]>nums[i]){
                p = i-1;
                break;
            }
        }

        int q = n-1;

        for(int i=n-2;i>=1;i--){
            if(nums[i]>nums[i+1]){
                q = i+1;
                break;
            }
        }

        if(p==0 || q==n-1) return false;

        for(int i=p+1;i<=q;i++){
            if(nums[i]>nums[i-1]) return false;
        }

        return true;
    }
};
