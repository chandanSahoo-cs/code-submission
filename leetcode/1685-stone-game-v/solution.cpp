class Solution {
public:
    int dp[505][505];

    int rec(vector<int>&pref, int l, int r){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        int sum = 0;

        for(int i=l;i<r;i++){
            int left = pref[i]-pref[l-1];
            int right = pref[r]-pref[i];

            if(left>right){
                sum = max(sum,right+rec(pref,i+1,r));
            }else if(right>left){
                sum = max(sum,left+rec(pref,l,i));
            }else{
                sum = max({sum,left+rec(pref,l,i),right+rec(pref,i+1,r)});
            }
        }

        return dp[l][r] = sum;
    }

    int stoneGameV(vector<int>& st) {
        int n = st.size();
        vector<int>pref(n+1);

        for(int i=1;i<=n;i++){
            pref[i] = st[i-1]+pref[i-1];
        }
        memset(dp,-1,sizeof(dp));
        return rec(pref,1,n);
    }
};
