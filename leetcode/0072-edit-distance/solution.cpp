class Solution {
public:
    int dp[505][505];
    
    int rec(string &word1, string &word2, int i, int j){
        int n = word1.size(), m = word2.size();

        if(i>=n && j>=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int mn = 1e5;

        if(i<n) mn = min(mn,1+rec(word1,word2,i+1,j));
        if(j<m){
            if(i<n) mn = min(mn,(word1[i]!=word2[j])+rec(word1,word2,i+1,j+1));
            mn = min(mn,1+rec(word1,word2,i,j+1));
        }

        return dp[i][j] = mn;
    }

    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));

        return rec(word1,word2,0,0);
    }
};
