class Solution {
    int dp[305][305];
    int cnt=0;
public:
   int rec(vector<vector<int>>&a, int i , int j){
        int n = a.size();
        int m = a[0].size();

        if(i==n || j==m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;

        int t1 = rec(a,i+1,j);
        int t2 = rec(a,i,j+1);
        int t3 = rec(a,i+1,j+1);

        if(a[i][j]){
            ans = 1+min({t1,t2,t3});
            cnt+=ans;
        }

        return dp[i][j] = ans;
    }
    
    int countSquares(vector<vector<int>>& a) {
        memset(dp,-1,sizeof(dp));
        rec(a,0,0);

        return cnt;
    }
};
