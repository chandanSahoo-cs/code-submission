const int mod = 1e9+7;

class Solution {
public:
    int dp[505][505];

    int rec(int p, int d){
        if(p==0 && d==0) return 1;

        if(dp[p][d]!=-1) return dp[p][d];
        
        int c1 = 0, c2 = 0;

        if(p>0){
            c1 = (p*1LL*rec(p-1,d+1))%mod;
        }

        if(d>0){
            c2= (d*1LL*rec(p,d-1))%mod;
        }

        return dp[p][d] = (c1+c2)%mod;
    }

    int countOrders(int n) {
        memset(dp,-1,sizeof(dp));


        return rec(n,0);
    }
};
