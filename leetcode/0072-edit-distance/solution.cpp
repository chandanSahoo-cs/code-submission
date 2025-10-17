class Solution {
    int dp[505][505];
public:

    int rec(string &s1, string &s2, int i,int j){

        int n = s1.size();
        int m = s2.size();

        if(i==n) return m-j;
        if(j==m) return n-i;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;

        if(s1[i]==s2[j]){
            ans = rec(s1,s2,i+1,j+1);
        }else{
            ans = min({1+rec(s1,s2,i,j+1),1+rec(s1,s2,i+1,j),1+rec(s1,s2,i+1,j+1)});
        }


        return dp[i][j] = ans;

    }

    int minDistance(string s1, string s2) {
        memset(dp,-1,sizeof(dp));

        return rec(s1,s2,0,0);
    }
};
