const int mod = 1e9+7;
class Solution {
public:
    int dp[105][105][105];

    int rec(string &word1, string &word2, string &target, int i, int j, int k){
        int n = word1.size(), m = word2.size(), l = target.size();

        if(k==l){
            return i&&j;
        }

        if(i==n && j==m) return 0;

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        int cnt = 0;

        for(int x=i;x<n;x++){
            if(word1[x]==target[k]) cnt = (cnt+0LL+rec(word1,word2,target,x+1,j,k+1))%mod;
        }

        for(int y=j;y<m;y++){
            if(word2[y]==target[k]) cnt = (cnt+0LL+rec(word1,word2,target,i,y+1,k+1))%mod;
        }

        return dp[i][j][k]= cnt;
    }
    
    int interleaveCharacters(string word1, string word2, string target) {
        memset(dp,-1,sizeof(dp));

        return rec(word1,word2,target,0,0,0);
    }
};
