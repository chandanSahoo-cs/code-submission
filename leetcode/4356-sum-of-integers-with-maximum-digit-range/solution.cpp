class Solution {
public:
    int compute(int n){
        int mx = 0, mn = 9;

        while(n){
            mx = max(mx,n%10);
            mn = min(mn,n%10);

            n/=10;
        }

        return mx-mn;
    }

    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();

        vector<int>store(n);

        int mx = 0;
        for(int i=0;i<n;i++){
            store[i] = compute(nums[i]);
            mx = max(store[i],mx);
        }

        int sum = 0;
        
        for(int i=0;i<n;i++){
            if(store[i]==mx) sum+=nums[i];
        }

        return sum;
    }
};
