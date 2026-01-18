class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        
        int n = grid.size(),m = grid[0].size();

        vector<vector<int>>row(n+1,vector<int>(m+1));
        vector<vector<int>>col(n+1,vector<int>(m+1));
        vector<vector<int>>diag1(n+1,vector<int>(m+1));
        vector<vector<int>>diag2(n+2,vector<int>(m+2));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i+1][j+1]+=row[i+1][j]+grid[i][j];
                col[i+1][j+1]+=col[i][j+1]+grid[i][j];
                diag1[i+1][j+1]+=diag1[i][j]+grid[i][j];
                diag2[i+1][j+1]+=diag2[i][j+2]+grid[i][j];
            }
        }

        int mx = 1;


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                

                for(int side=min(n-i+1,m-j+1);side>=1;side--){
                    int check=-1;
                    bool flag = true;

                    for(int k=i;k<i+side;k++){
                        if(check!=-1 && row[k][j+side-1]-row[k][j-1]!=check) {
                            flag=false;
                            break;
                        }
                        check=row[k][j+side-1]-row[k][j-1];
                    }

                    for(int k=j;k<j+side;k++){
                        if(col[i+side-1][k]-col[i-1][k]!=check) {
                            flag=false;
                            break;
                        }
                    }
                
                    if(flag){
                        if(check==diag1[i+side-1][j+side-1]-diag1[i-1][j-1] && 
                           check==diag2[i+side-1][j]-diag2[i-1][j+side]){
                            mx = max(mx,side);
                            break;
                        }
                    }
                }
            }
        }


        return mx;
    }
};
