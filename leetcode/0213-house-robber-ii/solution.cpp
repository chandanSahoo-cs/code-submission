class Solution {
    int dp[105];
public:
    int rec(int n, vector<int>&a, int i){

        for(int j=n-1;j>=i;j--){
            if(j==n-1) dp[j]=a[j];
            else{
                dp[j]=a[j];
                dp[j]=max(dp[j],dp[j+1]);
                if(j+2<n){
                    dp[j] = max(dp[j],a[j]+dp[j+2]);
                }
            }
        }

        return dp[i];
    }

    int rob(vector<int>& a) {
        int n = a.size();
        if(n==1) return a[0];
        int p1 = rec(n-1,a,0);
        int p2 = rec(n,a,1);

        return max(p1,p2);
    }
};
