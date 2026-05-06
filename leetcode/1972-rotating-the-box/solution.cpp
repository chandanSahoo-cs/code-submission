class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>>ans(m,vector<char>(n,'.'));

        for(int i=n-1;i>=0;i--){
            int k = m-1;
            for(int j=m-1;j>=0;j--){
                if(boxGrid[i][j]=='*'){
                    ans[j][n-1-i]='*';
                    k=j-1;
                }else if(boxGrid[i][j]=='#'){
                    ans[k][n-1-i]='#';
                    k--;
                }
            }
        }

        return ans;
    }
};
