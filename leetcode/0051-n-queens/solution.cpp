class Solution {
public:
    vector<vector<string>>ans;

    void rec(int n , vector<int>&r, vector<int>&c, vector<int>&di1, vector<int>&di2, vector<string>s,int i){
        if(i==n){
            ans.push_back(s);
            return;
        }

        for(int j=0;j<n;j++){
            if(c[j] || di1[i+j] || di2[n-i+j]) continue;

            s[i][j]='Q';
            r[i]=c[j]=di1[i+j]=di2[n-i+j]=1;

            rec(n,r,c,di1,di2,s,i+1);

            s[i][j]='.';
            r[i]=c[j]=di1[i+j]=di2[n-i+j]=0;
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int>row(n),col(n),di1(2*n),di2(2*n);
        vector<string>s(n,string(n,'.'));
        rec(n,row,col,di1,di2,s,0);
        return ans;
    }
};
