class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        // int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i>nums.size()-3 && nums[i]==0) return -1;
            if(nums[i]==0){
                nums[i]=1;
                nums[i+1]=(nums[i+1]==0?1:0);
                nums[i+2]=(nums[i+2]==0?1:0);
                cnt++;
            }
        }
        return cnt;
    }
};
