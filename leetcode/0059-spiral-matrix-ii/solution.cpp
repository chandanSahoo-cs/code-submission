class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));

        int i=0,j=0,l=n-1,b=n-1;
        int num=1;
        while(i<=b && j<=l){
            for(int k=j;k<=l;k++){
                ans[i][k]=num;
                num++;
            }
            i++;

            for(int k=i;k<=b;k++){
                ans[k][l]=num;
                num++;
            }
            l--;

            for(int k=l;k>=j;k--){
                ans[b][k]=num;
                num++;
            }
            b--;

            for(int k=b;k>=i;k--){
                ans[k][j]=num;
                num++;
            }
            j++;
        }

        return ans;
    }
};
