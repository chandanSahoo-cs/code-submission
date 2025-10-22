class Solution {
public:
    int mark[2005][2005];
    int dp[2005];
    
    void markPal(string &s){
        int n = s.size();

        for(int i=0;i<n;i++){
            //Even
            int l = i,r=i+1;

            while(l>=0 && r<n && s[l]==s[r]){
                mark[l][r]=1;
                l--;
                r++;
            }

            //Odd
            l=i,r=i;

            while(l>=0 && r<n && s[l]==s[r]){
                mark[l][r]=1;
                l--;
                r++;
            }

        }
    }

    int rec(string &s, int i){
        int n = s.size();

        if(i==n) return -1;
        if(dp[i]!=-1) return dp[i];

        int ans = INT_MAX;
        for(int j=i;j<n;j++){
            if(mark[i][j]==1){
                ans = min(ans,1+rec(s,j+1));
            }
        }

        // if(ans==INT_MAX) ans = 0;

        return dp[i] = ans;
    }

    int minCut(string s) {
        memset(dp,-1,sizeof(dp));

        markPal(s);
        return rec(s,0);
    }
};
