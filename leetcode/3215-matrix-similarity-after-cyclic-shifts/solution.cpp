class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        int r = k%m;
        int l = m-r;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=mat[i][(j+l)%m]) return false;
                // if(j%2){
                // }else{
                //     if(mat[i][j]!=mat[i][(j+l)%m]) return false;
                // }
            }
        }

        return true;
    }
};
