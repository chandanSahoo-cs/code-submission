class Solution {
public:
    int dp[305][305];

    int cnt=0;
    int rec(vector<vector<int>>& matrix, int i, int j){
        int n = matrix.size();
        int m = matrix[0].size();

        if(i==n || j==m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int sz=INT_MAX;

        sz = min(sz,1+rec(matrix,i+1,j));
        sz = min(sz,1+rec(matrix,i,j+1));
        sz = min(sz,1+rec(matrix,i+1,j+1));

        cnt+=(matrix[i][j]==0?0:sz);
        return dp[i][j]=(matrix[i][j]==0?0:sz);
    }

    int countSquares(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        rec(matrix,0,0);

        return cnt;    
    }
};
