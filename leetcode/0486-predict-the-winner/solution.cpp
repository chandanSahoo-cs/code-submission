class Solution {
public:
    int dp[25][25];

    int rec(vector<int>&pref, int l, int r){
        if(l>r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int total = pref[r+1]-pref[l];
        int taken = max(total-rec(pref,l+1,r),total-rec(pref,l,r-1));

        return dp[l][r] = taken;
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<int>pref(n+1);
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i]+nums[i];
        }

        memset(dp,-1,sizeof(dp));

        int p1 = rec(pref,0,n-1);
        int p2 = pref[n]-p1;
        
        return p1>=p2;
    }
};
