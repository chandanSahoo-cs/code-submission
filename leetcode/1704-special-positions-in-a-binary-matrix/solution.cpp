class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int sum = 0;

        vector<int>row(n),col(m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i]+=(mat[i][j]==0);
                col[j]+=(mat[i][j]==0);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(mat[i][j]==1 && row[i]==m-1 && col[j]==n-1) sum++;
            }
        }

        return sum;
    }
};
