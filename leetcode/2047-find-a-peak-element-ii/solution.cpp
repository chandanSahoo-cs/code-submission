class Solution {
    #define ll long long
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    vector<int>ans;
        int m=mat.size();
        int n=mat[0].size();
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int mx=INT_MIN;
            int mxInd;
            for(ll i=0;i<m;i++){
                if(mat[i][mid]>mx){
                    mx=mat[i][mid];
                    mxInd=i;
                } 
            }
            if((mid==0 || mat[mxInd][mid]>mat[mxInd][mid-1]) && (mid==n-1 || mat[mxInd][mid]>mat[mxInd][mid+1])) {
                ans={mxInd,mid};
                break;
            }
            else if(((mid==0 || mat[mxInd][mid]>mat[mxInd][mid-1]) && mat[mxInd][mid]<mat[mxInd][mid+1])) s=mid+1;
            else if(((mid==n-1 || mat[mxInd][mid]>mat[mxInd][mid+1]) && mat[mxInd][mid]<mat[mxInd][mid-1])) e=mid-1;
        }
        return ans;
    }
};
