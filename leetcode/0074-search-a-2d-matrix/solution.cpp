class Solution {
    #define ll long long
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ll m=matrix.size();
        ll n=matrix[0].size();
        ll s=0,e=m-1;
        bool flag=false;
        while(s<e){
            ll mid=s+(e-s)/2;
            if(matrix[mid][n-1]==target) {
                flag=true;
                break;
            }
            if(matrix[mid][n-1]<target) s=mid+1;
            else e=mid;
        }
        if(!flag){
            ll temp=e;
            s=0,e=n-1;
            while(s<=e){
                ll mid=s+(e-s)/2;
                if(matrix[temp][mid]==target){
                    flag=true;
                    break;
                }
                else if(matrix[temp][mid]<target) s=mid+1;
                else e=mid-1;
            }
        }
        return flag;
    }
};
