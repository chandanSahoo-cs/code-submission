const int mod = 1e9+7;
class Solution {
public:

    vector<int>dp[105][105];
 
    vector<int> rec(vector<string>& board, int i, int j){
        
        if(i==0 && j==0) return {0,1};
        if(i<0 || j<0) return {0,0};

        if(dp[i][j][0]!=-1) return dp[i][j];

        vector<int>ans = {0,0};

        if(board[i][j]!='X'){
            auto v1 = rec(board,i-1,j);
            auto v2 = rec(board,i,j-1);
            auto v3 = rec(board,i-1,j-1);

            int mx = max({v1[0],v2[0],v3[0]});
            int cnt = 0;

            if(v1[0]==mx) cnt=(cnt+v1[1])%mod;
            if(v2[0]==mx) cnt=(cnt+v2[1])%mod;
            if(v3[0]==mx) cnt=(cnt+v3[1])%mod;

            ans = {cnt==0?0:(board[i][j]=='S'?0:board[i][j]-'0')+mx,cnt};
        }

        return dp[i][j] = ans;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = {-1,-1};
            }
        }

        return rec(board,n-1,m-1);
    }
};

/*
E 2 3
2 X 2
1 2 S
*/
