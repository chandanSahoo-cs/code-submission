class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int gMax = nums[0];
        int cMax = nums[0];

        int end = 0;
        int tempStrt = 0;

        int len = 1;

        for(int i = 1; i <n ;i++){
            if(nums[i]>(cMax&nums[i])){
                cMax=nums[i];
                tempStrt = i;
            }
            else{
                cMax&=nums[i];
            }
            end++;
            if(cMax==gMax){
                gMax = cMax;
                len = max(len,end-tempStrt+1);
            }
            else if(cMax>gMax){
                gMax = cMax;
                len = end-tempStrt+1;
            }
        }
        return len;
    }
};
