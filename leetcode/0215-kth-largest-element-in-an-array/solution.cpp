class Solution {
public:

    int quickselect(vector<int>& nums,int left,int right,int k){
        if(left == right){
            return nums[left];
        }

        int pi = left + (right - left) / 2;
        int pv = nums[pi];

        int i = left;
        int j = right;

        while(i <= j){
            while(nums[i] < pv){
                i++;
            }
            while(nums[j] > pv){
                j--;
            }

            if(i <= j){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }

        if(k <= j){
            return quickselect(nums,left,j,k);
        }
        else if( k >= i){
            return quickselect(nums,i,right,k);
        }
        else{
            return nums[k];
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickselect(nums,0,n-1,n-k);
    }
};
