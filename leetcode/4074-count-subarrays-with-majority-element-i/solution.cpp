class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int cnt = 0;

        for(int i=0;i<n;i++){
            int trgCnt = 0;
            for(int j=i;j<n;j++){
                trgCnt += (nums[j]==target);

                if(trgCnt>(j-i+1)/2) cnt++;
            }
        }

        return cnt;
    }
};
