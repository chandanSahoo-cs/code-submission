class Solution {
public:
    int dp[100005];
    bool rec(int n){
        if(n==0) return false;

        if(dp[n]!=-1) return dp[n];

        bool flag = true;

        for(int i=1;i*i<=n;i++){
            flag &=rec(n-i*i);
        }

        return dp[n] = !flag;
    }

    bool winnerSquareGame(int n) {
        for(int i=0;i<=n;i++){
            dp[i]=-1;
        }

        return rec(n);    
    }
};
