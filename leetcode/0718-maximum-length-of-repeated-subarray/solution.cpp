class Solution {
public:
    int dp[1005][1005];
    int mx = 0;

    int rec(vector<int>&a, vector<int>&b, int i, int j){
        int n = a.size(), m = b.size();

        if(i>=n || j>=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;

        if(a[i]==b[j]){
            ans = 1+rec(a,b,i+1,j+1);
            mx = max(mx,ans);
        }
        rec(a,b,i+1,j);
        rec(a,b,i,j+1);

        return dp[i][j] = ans;
    }

    int findLength(vector<int>& a, vector<int>& b) {
        memset(dp,-1,sizeof(dp));

        rec(a,b,0,0);

        return mx;
    }
};
