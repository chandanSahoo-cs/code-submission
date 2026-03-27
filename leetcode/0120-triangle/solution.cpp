class Solution {
    // int dp[205];
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();

        vector<int>curr(205),prev(205);

        for(int i=n-1;i>=0;i--){
            int m = a[i].size();
            for(int j=0;j<=m-1;j++){
                if(i==n-1) curr[j] = a[i][j];
                else{
                    int ans = min(prev[j],prev[j+1]);
                    curr[j]= ans+a[i][j];
                }
            }
            prev=curr;
            curr.assign(205,0);
        }
        return prev[0];    
    }
};
