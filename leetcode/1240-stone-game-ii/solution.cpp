class Solution {
public:
    int dp[105][105];
    int rec(vector<int>&pref, int i, int m){
        int n = pref.size();
        
        if(i>=n) return 0;
        if(dp[i][m]!=-1) return dp[i][m];

        int mx = 0;
        for(int j = 1;j<=2*m && i+j-1<n;j++){
            int curr = pref[i+j-1]-(i-1<0?0:pref[i-1]);
            int p = rec(pref,i+j,max(j,m));

            mx = max(mx,curr+pref[n-1]-pref[i+j-1]-p);
        }

        return dp[i][m] = mx;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int>pref(n);

        pref[0] = piles[0];

        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+piles[i];
        }

        memset(dp,-1,sizeof(dp));

        return rec(pref,0,1); 
    }
};
