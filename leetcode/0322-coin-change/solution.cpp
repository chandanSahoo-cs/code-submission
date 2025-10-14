class Solution {
public:

    // int rec(vector<int>&a, int amt){
    //     int n = a.size();


    //     int ans = INT_MAX;
    //     bool flag = false;

    //     for(int i=0;i<n;i++){
    //         if(amt-a[i]<0) continue;
    //         int temp = rec(a,amt-a[i]);
    //         if(temp!=-1) {
    //             flag = true;
    //             ans = min(temp,ans);
    //         }
    //     }

    //     mark[amt]=true;
    //     if(!flag) return dp[amt] = -1;
    //     else return dp[amt] = ans+1; 
    // }

    int coinChange(vector<int>& a, int amount) {
        int n = a.size();
        vector<int>dp(amount+1,-1);

        for(int j=0;j<=amount;j++){
            if(j==0) dp[j]=0;
            else{
                int ans = INT_MAX;
                bool flag = false;
                for(int i=0;i<n;i++){
                    if(j-a[i]<0) continue;
                    int temp = dp[j-a[i]];
                    if(temp!=-1) {
                        flag = true;
                        ans = min(temp,ans);
                    }
                }

                if(flag) dp[j] = ans+1;
            }
        }

        return dp[amount];
    }
};
