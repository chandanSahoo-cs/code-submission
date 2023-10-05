class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int rows=mat.size();
        int ans=0;
        for(int i=0;i<rows;i++){
            ans+=mat[i][i];
            ans+=mat[i][rows-i-1];
        }
        if (rows%2!=0){
            ans-=mat[rows/2][rows/2];
        }
    return ans;
    }
};
