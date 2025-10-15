class Solution {
    int dp[505][505];
public:

    int rec(string &s1, string &s2, int i, int j){
        int n = s1.size();
        int m = s2.size();

        // if(i>=n && j<m) return 1;
        // if(i<n && j>=m) return 1;
        if(i>=n && j>=m) return 0; 

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 1e9;
        if(i>=n || j>=m){
            if(i<n){
                ans = 1+rec(s1,s2,i+1,j);
            }else{
                ans = 1+rec(s1,s2,i,j+1);
            }
        }else if(s1[i]==s2[j]){
            ans = rec(s1,s2,i+1,j+1);
        }else{
            ans = min(ans,1+rec(s1,s2,i+1,j));
            ans = min(ans,1+rec(s1,s2,i,j+1));
        }

        return dp[i][j] = ans;
    }

    int minDistance(string s1, string s2) {
        memset(dp,-1,sizeof(dp));

        return rec(s1,s2,0,0);
    }
};
