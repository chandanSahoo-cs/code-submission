class Solution {
    int dp[105][105];
public:
    int rec(vector<int>&a,int l, int r){
        if(r-l<=1) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int ans=INT_MAX;

        for(int i=l+1;i<r;i++){
            ans = min(ans,a[r]-a[l]+rec(a,l,i)+rec(a,i,r));
        }

        return dp[l][r] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());

        vector<int>a;
        a.push_back(0);
        for(auto ele:cuts) a.push_back(ele);
        a.push_back(n);

        return rec(a,0,a.size()-1);    
    }
};
