class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int jump=0;   
        for(int i=0;i<n;i++){
            jump=max(jump-1,nums[i]);
            if(jump<0) return false;
            if(i!=n-1 && jump==0) return false;
        }

        return true;
    }
};
