class Solution {
public:
    int dp[100005];

    int rec(vector<int>&pref, int i){
        int n = pref.size();

        if(i==n-2) return pref[n-1];

        if(dp[i]!=-1) return dp[i];
        
        int p = rec(pref,i+1);
        int mx = max(p,pref[i+1]-p);

        return dp[i] = mx;
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int>pref(n);
        pref[0] = stones[0];

        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1]+stones[i];
        }

        for(int i=0;i<n;i++){
            dp[i] = -1;
        }

        return rec(pref,0);
    }
};
