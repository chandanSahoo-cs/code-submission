class Solution {
public:
    int queen[10];
    vector<vector<string>>ans;

    bool check(int row, int col){
        for(int i=0;i<row;i++){
            int pRow = i;
            int pCol = queen[i];

            if(col==pCol || abs(pRow-row)==abs(pCol-col)) return false;
        }
        return true;
    }

    void rec(int n, int row, int col, vector<string>&s){
        
        if(row==n){
            for(int i=0;i<n;i++){
                s[i][queen[i]]='Q';
            }
            ans.push_back(s);
            for(int i=0;i<n;i++){
                s[i][queen[i]]='.';
            }
            return;
        }

        if(col==n) return;

        if(check(row, col)){
            queen[row]=col;
            rec(n,row+1,0,s);
            queen[row]=-1;
        }
        rec(n,row,col+1,s);
    }

    vector<vector<string>> solveNQueens(int n) {
        memset(queen,-1,sizeof(queen));
        vector<string>s;

        string temp = "";

        for(int i=0;i<n;i++){
            temp.push_back('.');
        }    
        for(int i=0;i<n;i++){
            s.push_back(temp);
        }

        rec(n,0,0,s);

        return ans;
    }
};
