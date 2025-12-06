class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();

        if(n*m!=r*c) return mat;

        vector<vector<int>>ans(r,vector<int>(c));

        int kr=0, kc=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[kr][kc]=mat[i][j];
                kc++;
                if(kc==c){
                    kc=0;
                    kr++;
                    // if(kr==)
                }
            }
        }

        return ans;
    }
};
