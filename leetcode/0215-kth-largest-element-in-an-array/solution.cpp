class Solution {
public:
    int quickSelect(vector<int>&nums,int l, int r, int k){
        if(l==r) return nums[l];

        int p = l+(r-l)/2;
        int pivot = nums[p];

        int i = l;
        int j = r;

        while(i<=j){
            while(nums[i]<pivot) i++;
            while(nums[j]>pivot) j--;

            if(i<=j){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }

        if(k>=i) return quickSelect(nums,i,r,k);
        else if(k<=j) return quickSelect(nums,l,j,k);
        else return nums[k];
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums,0,n-1,n-k);
    }
};
