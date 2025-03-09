class Solution {
public:
    vector<vector<string>>ans;

    void fn(int n, int i, int j,vector<int>&c, vector<int>&di1, vector<int>&di2,vector<string>&s){
        if(i==n){
            ans.push_back(s);
            return;
        }
        if(j==n) return;

        if(!c[j] && !di1[i+j] && !di2[n-i+j]){
            s[i][j]='Q';
            c[j]=1;
            di1[i+j]=1;
            di2[n-i+j]=1;
            fn(n,i+1,0,c,di1,di2,s);
            s[i][j]='.';
            c[j]=0;
            di1[i+j]=0;
            di2[n-i+j]=0;
        }
        fn(n,i,j+1,c,di1,di2,s);

        return;
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<int>c(n),di1(2*n),di2(2*n);
        vector<string>s(n,string(n,'.'));
        fn(n,0,0,c,di1,di2,s);
        return ans;    
    }
};
