class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        vector<int>f(n);
        
        int fsum = 0;
        int sum = 0;

        for(int i=0;i<n;i++){
            fsum+=nums[i]*i;
            sum+=nums[i];
        }

        f[0] = fsum;
        int mx = f[0];

        for(int i=1;i<n;i++){
            f[i] = f[i-1]+sum-n*nums[n-i];
            mx = max(mx,f[i]);
        }

        return mx;
    }
};
