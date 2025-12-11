class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l=0,r=n-1;
        int ind=l;
        while(l<=r){
            int mid = l+(r-l)/2;

            if(target<matrix[mid][0]){
                r=mid-1;
            }else{
                ind=mid;
                l=mid+1;
            }
        }

        l=0,r=m-1;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(target==matrix[ind][mid]) return true;
            else if(target<matrix[ind][mid]){
                r=mid-1;
            }else l=mid+1;
        }

        return false;
    }
};
