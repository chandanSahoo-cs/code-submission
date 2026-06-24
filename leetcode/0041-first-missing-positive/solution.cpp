class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        bool one = false;

        for(auto &ele:nums){
            if(ele==1) one = true;
            if(ele>n || ele<=0) ele=1;
        }

        if(!one) return 1;

        for(auto ele:nums){
            int val = abs(ele);
            nums[val-1] = -abs(nums[val-1]);
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0) return i+1;
        }

        return n+1;
    }
};
