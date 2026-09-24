class Solution {
public:
    int compute(int a){
        int sum=0;
        while(a){
            sum+=a%10;
            a/=10;
        }
        
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(compute(nums[i])==i) return i;
        }
        return -1;
    }
};
