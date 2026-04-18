class Solution {
public:
    int dp[205][205];
    
    int rec(vector<vector<int>>& matrix, int i, int j){
        int n = matrix.size(), m = matrix[0].size();

        if(i>=n || j>=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        int mx = 0;
        for(int k=0;k<4;k++){
            int r = i+dr[k];
            int c = j+dc[k];

            if(r<n && c<m && r>=0 && c>=0 && matrix[i][j]<matrix[r][c]){
                mx = max(mx,rec(matrix,r,c));
            }
        }

        return dp[i][j] = 1+mx;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        memset(dp,-1,sizeof(dp));

        int mx = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mx = max(mx,rec(matrix,i,j));
            }
        }

        return mx;
    }
};
