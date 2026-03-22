class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        bool flag90=true;
        bool flag180=true;
        bool flag270=true;
        bool flag0=true;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[i][j]) flag0=false;
                if(mat[j][n-1-i]!=target[i][j]) flag90=false;
                if(mat[n-1-i][n-1-j]!=target[i][j]) flag180=false;
                if(mat[n-1-j][i]!=target[i][j]) flag270=false;
            }
        }

        return flag0 | flag90 | flag180 | flag270;
    }
};
