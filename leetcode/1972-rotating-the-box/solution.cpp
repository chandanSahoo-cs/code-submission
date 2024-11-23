class Solution {
#define ll long long

public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        for(int i=n-1;i>=0;i--){
            int pt=m-1;
            for(int j=m-1;j>=0;j--){
                if(a[i][j]=='#'){
                    ans[pt][n-1-i]='#';
                    pt--;
                }
                else if(a[i][j]=='*'){
                    ans[j][n-1-i]='*';
                    pt=j-1;
                }
            }
        }
        return ans;
    }
};
