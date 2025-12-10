class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int r=n-1;

        int i=nums1.size()-1,j=m-1;

        while(r>=0 && j>=0){
            if(nums1[r]>nums2[j]){
                nums1[i]=nums1[r];
                r--;
            }else{
                nums1[i]=nums2[j];
                j--;
            }
            i--;
        }

        while(r>=0){
            nums1[i]=nums1[r];
            i--;
            r--;
        }

        while(j>=0){
            nums1[i]=nums2[j];
            i--;
            j--;
        }
    }
};
