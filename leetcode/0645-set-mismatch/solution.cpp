class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>freq(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int rptdNum;
        int mssngNum;
        for(int i=1;i<freq.size();i++){
            if(freq[i]==2) rptdNum=i;
            if(freq[i]==0) mssngNum=i;
        }
        return {rptdNum,mssngNum};
    }
};
