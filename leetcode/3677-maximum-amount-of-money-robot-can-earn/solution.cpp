const int NEGINF = -1e9;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();

        vector<vector<int>>next(m+1,vector<int>(3));
        vector<vector<int>>curr(m+1,vector<int>(3));

        for(int j=0;j<=m;j++){
            for(int k=0;k<=2;k++){
                next[j][k]=NEGINF;
            }
        }

        curr[m][0] = curr[m][1] = curr[m][2] = NEGINF;

        if(coins[n-1][m-1]<0){
            curr[m-1][2] = curr[m-1][1] = 0;
            curr[m-1][0] = coins[n-1][m-1];
        }else curr[m-1][2] = curr[m-1][1] = curr[m-1][0] = coins[n-1][m-1];

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;
                for(int k=0;k<=2;k++){

                    int ans = 0;

                    if(coins[i][j]>=0){
                        ans=coins[i][j]+max(next[j][k],curr[j+1][k]);
                    }else{
                        int p1=NEGINF,p2=NEGINF;

                        if(k>0){
                            p1 = max(next[j][k-1],curr[j+1][k-1]);
                        }
                        p2 = coins[i][j]+max(next[j][k],curr[j+1][k]);

                        ans = max(p1,p2);
                    }

                    curr[j][k] = ans;
                }
            }
            next = curr;
        }

        return next[0][2];
    }
};
