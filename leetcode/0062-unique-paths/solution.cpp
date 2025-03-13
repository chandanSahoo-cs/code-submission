#define ll long long

class Solution {
public:

    int uniquePaths(int m, int n) {
        int mx = max(m-1,n-1);
        int mn = min(m-1,n-1);

        ll num = 1;
        ll denom = 1;

        vector<int>mark(mn+1,1);

        for(int i = (mx+mn);i>=mx+1;i--){
            int carr = i;
            for(int j=mn;j>=1;j--){
                if(mark[j] && carr%j==0){
                    carr/=j;
                    mark[j]=0;
                }
            }
            num*=carr;
        }

        for(int i=1;i<=mn;i++){
            if(mark[i]) denom*=i;
        }

        return num/denom;
    }
};
