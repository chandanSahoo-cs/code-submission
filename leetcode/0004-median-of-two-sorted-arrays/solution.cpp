class Solution {
public:
    const int mod = 1e9+7;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        if(n>m) return findMedianSortedArrays(nums2,nums1);

        int req = (n+m+1)/2;
        int left = max(0,req-m), right = min(n,req);

        while(left<=right){
            int mid = left+(right-left)/2;
            int cut = req-mid;

            int l1 = mid==0?-mod:nums1[mid - 1];
            int r1 = mid==n?mod:nums1[mid];

            int l2 = cut==0?-mod:nums2[cut-1];
            int r2 = cut==m?mod:nums2[cut];
 
            if(l1>r2){
                right = mid-1;
            }else if(l2>r1){
                left = mid+1;
            }else{
                if((n+m)%2){
                    return max(l1,l2);
                }else{
                    return (double)(max(l1,l2)+min(r1,r2))/2;
                }
            }
        }


        return 0;
    }
};
