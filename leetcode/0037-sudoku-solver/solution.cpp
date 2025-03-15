class Solution {
public:

    bool verify(vector<vector<char>> &b){
        vector<int>check = {1,2,3,4,5,6,7,8,9};
        for(int i=0;i<9;i++){
            vector<int>a;
            for(int j=0;j<9;j++){
                a.push_back(b[i][j]-'0');
            }
            sort(a.begin(),a.end());
            if(a!=check) return false;
        }

        for(int i=0;i<9;i++){
            vector<int>a;
            for(int j=0;j<9;j++){
                a.push_back(b[j][i]-'0');
            }
            sort(a.begin(),a.end());
            if(a!=check) return false;
        }

        for(int i=0;i<9;i+=3){
            vector<int>a;
            for(int j=0;j<9;j+=3){
                for(int m=i;m<i+3;m++){
                    for(int n=j;n<j+3;n++){
                        a.push_back(b[m][n]-'0');
                    }
                }
            }
            sort(a.begin(),a.end());
            if(a!=check) return false;
        }

        return true;
    }


    bool solve(vector<vector<char>> &b, vector<vector<int>> &r,vector<vector<int>> &c, vector<vector<int>> &sg, int i, int j){
        if(i>=9) return true;
        if(j>=9) return solve(b,r,c,sg,i+1,0);
        if(b[i][j]!='.') return solve(b,r,c,sg,i,j+1);
        int bi = (i/3)*3+(j/3);
        for(int k=1;k<10;k++){
            if(!r[i+1][k] && !c[j+1][k] && !sg[bi+1][k]){
                r[i+1][k]=1;
                c[j+1][k]=1;
                sg[bi+1][k]=1;
                b[i][j] = char(k+'0');
                if(solve(b,r,c,sg,i,j+1)){
                    return true;
                }
                r[i+1][k]=0;
                c[j+1][k]=0;
                sg[bi+1][k]=0;
                b[i][j]='.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& b) {
        vector<vector<int>>row(10,vector<int>(10));
        vector<vector<int>>col(10,vector<int>(10));
        vector<vector<int>>sg(10,vector<int>(10));

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]!='.'){
                    row[i+1][b[i][j]-'0']=1;
                    col[j+1][b[i][j]-'0']=1;
                    int bi = (i/3)*3+(j/3);
                    sg[bi+1][b[i][j]-'0']=1;
                }
            }
        }
        solve(b,row,col,sg,0,0);
    }
};
