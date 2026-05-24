class Solution {
public:
    int dp[1005];
    int rec(vector<int>& arr, int i, int d){
        int n = arr.size();

        if(dp[i]!=-1) return dp[i];

        int ans = 0;

        for(int j=i-1;j>=max(i-d,0);j--){
            if(arr[j]>=arr[i]) break;
            ans = max(ans,rec(arr,j,d));
        }

        for(int j=i+1;j<=min(i+d,n-1);j++){
            if(arr[j]>=arr[i]) break;
            ans = max(ans,rec(arr,j,d));
        }

        return dp[i] = 1+ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        memset(dp,-1,sizeof(dp));

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,rec(arr,i,d));
        }

        return ans;
    }
};
