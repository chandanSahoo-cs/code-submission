class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int mxIdx1 = -1, mxIdx2 = -1;
        int mnIdx1 = -1, mnIdx2 = -1;

        for(int i=0;i<n;i++){
            if(mxIdx1==-1 || nums[i]>=nums[mxIdx1]){
                mxIdx2 = mxIdx1;
                mxIdx1 = i;
            }else if(mxIdx2==-1 || nums[i]>nums[mxIdx2]){
                mxIdx2 = i;
            }

            if(mnIdx1==-1 || nums[i]<=nums[mnIdx1]){
                mnIdx2 = mnIdx1;
                mnIdx1 = i;
            }else if(mnIdx2==-1 || nums[i]<nums[mnIdx2]){
                mnIdx2 = i;
            }
        }

        int mx = INT_MIN;

        for(int i=0;i<n;i++){
            if(i!=mxIdx1 && i!=mxIdx2){
                mx = max(mx,nums[i]*nums[mxIdx1]*nums[mxIdx2]);
            }
            if(i!=mnIdx1 && i!=mnIdx2){
                mx = max(mx,nums[i]*nums[mnIdx1]*nums[mnIdx2]);
            }
        }

        return mx;
    }
};
