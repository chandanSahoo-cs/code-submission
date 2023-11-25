class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int countB=count(nums.begin(),nums.end(),0);
        auto reqIndx=remove(nums.begin(),nums.end(),0);
        nums.erase(reqIndx,nums.end());
        for(int i=0;i<countB;i++){
            nums.push_back(0);
        }
        return;
    }
};
