class Solution {
public:
    // bool validateLCP(string &s, vector<vector<int>>& lcp){
    //     int n = s.size();

    //     for(int i=0;i<n;i++){
    //         if(lcp[i][n-1]!=(s[i]==s[n-1])) return false;
    //         if(lcp[n-1][i]!=(s[n-1]==s[i])) return false;
    //     }

    //     for(int i=n-2;i>=0;i--){
    //         for(int j=n-2;j>=0;j--){
    //             int val = s[i]==s[j]?1+lcp[i+1][j+1]:0;
    //             if(lcp[i][j]!=val) return false;
    //         }
    //     }

    //     return true;
    // }

    int rec(string &s,int i, int j,vector<vector<int>>&dp){
        int n = s.size();

        if(i==n || j==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int c1 = s[i]==s[j]?1+rec(s,i+1,j+1,dp):0;
        rec(s,i+1,j,dp);
        rec(s,i,j+1,dp);

        return dp[i][j]=s[i]==s[j]?c1:0;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        string s(n,'$');

        for(int i=0;i<n;i++){
            vector<bool>alpha(26,true);

            for(int j=0;j<n;j++){
                if(lcp[i][j]==0 && s[j]!='$'){
                    alpha[s[j]-'a']=false;
                }
            }

            for(int k=0;k<26;k++){
                if(alpha[k]){
                    s[i]=k+'a';
                    break;
                }
            }

            if(s[i]=='$') return "";
        }

        cout<<s;

        vector<vector<int>>dp(n,vector<int>(n,-1));
        rec(s,0,0,dp);

        return lcp==dp?s:"";
    }
};

/*
4 0 2 0
0 3 0 1
2 0 2 0
0 1 0 1
*/
