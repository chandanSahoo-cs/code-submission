class Solution {
public:
    vector<vector<string>>ans;
    vector<int>col;
    vector<int>di1;
    vector<int>di2;

    void toggle(int n, int i, int j){
        col[j]=!col[j];
        di1[i+j]=!di1[i+j];
        di2[n-i+j]=!di2[n-i+j];

        return ;
    }

    void rec(int n, vector<string> &board, int i ){
        if(i==n){
            ans.push_back(board);
            return;
        }

        for(int j=0;j<n;j++){
            if(!col[j] && !di1[i+j] && !di2[n-i+j]){
                toggle(n,i,j);
                board[i][j]='Q';
                rec(n,board,i+1);
                board[i][j]='.';
                toggle(n,i,j);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        col.resize(n);
        di1.resize(2*n);
        di2.resize(2*n);

        vector<string>board;

        for(int i=0;i<n;i++){
            string s(n,'.');
            board.push_back(s);
        }

        rec(n,board,0);

        return ans;
    }
};
