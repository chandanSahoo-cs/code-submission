class Solution {
public:

    vector<vector<int>>row;
    vector<vector<int>>col;
    vector<vector<int>>box;

    bool check(int i, int j, int b, char val){

        if(row[i][val-'0'] || col[j][val-'0'] || box[b][val-'0']) return false;

        return true;
    }

    bool rec(vector<vector<char>>& board, int i, int j){
        if(i==9) return 1;

        if(j==9){
            return rec(board,i+1,0);
        }else if(board[i][j]!='.'){
            return rec(board,i,j+1);
        }
        else{
            for(char c='1';c<='9';c++){
                int b = (i/3)*3+j/3;
                if(check(i,j,b,c)){
                    board[i][j]=c;
                    row[i][c-'0']=1;
                    col[j][c-'0']=1;
                    box[b][c-'0']=1;

                    int val = rec(board,i,j+1);
                    if(val) return 1;

                    board[i][j]='.';
                    row[i][c-'0']=0;
                    col[j][c-'0']=0;
                    box[b][c-'0']=0;
                }
            }
        }

        return 0;
    }

    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9,vector<int>(10));
        col.resize(9,vector<int>(10));
        box.resize(9,vector<int>(10));

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int c = board[i][j]-'0';
                int b = (i/3)*3+j/3;
                row[i][c] = col[j][c] = box[b][c] = 1;
            }
        }

        rec(board,0,0);

        return;
    }
};
