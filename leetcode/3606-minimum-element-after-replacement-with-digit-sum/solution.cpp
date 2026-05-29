class Solution {
public:
    int digitSum(int ele){
        int sum = 0;

        while(ele){
            sum+=ele%10;
            ele/=10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {
        int mn = INT_MAX;

        for(auto ele:nums) mn = min(mn,digitSum(ele));

        return mn;
    }
};
