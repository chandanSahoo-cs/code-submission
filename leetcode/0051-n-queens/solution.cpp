class Solution {
public:
    vector<vector<string>>ans;

    void rec(int n, int i, int j, vector<int>&r, vector<int>&c, vector<int>&di1,vector<int>&di2,vector<string>&s){
        if(i==n){
            ans.push_back(s);
            return;
        }
        if(j==n){
            return;
        }

        if(!r[i] && !c[j] && !di1[i+j] && !di2[n-i+j]){
            s[i][j]='Q';
            r[i]=c[j]=di1[i+j]=di2[n-i+j]=1;
            rec(n,i+1,0,r,c,di1,di2,s);
            s[i][j]='.';
            r[i]=c[j]=di1[i+j]=di2[n-i+j]=0;
        }

        rec(n,i,j+1,r,c,di1,di2,s);

        return;
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<int>r(n),c(n),di1(2*n),di2(2*n);
        vector<string>s(n,string(n,'.'));
        rec(n,0,0,r,c,di1,di2,s);
        return ans;
    }
};
