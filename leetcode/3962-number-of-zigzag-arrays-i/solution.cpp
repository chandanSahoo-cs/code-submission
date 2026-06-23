class Solution {
public:
    const int mod = 1e9+7;
    int zigZagArrays(int n, int l, int r) {
        int m = r-l+1;

        vector<int>curr0(m,0);
        vector<int>curr1(m,0);
        vector<int>prev0(m,0);
        vector<int>prev1(m,0);

        for(int i=0;i<m;i++){
            prev0[i]=prev1[i]=1;
        }

        for(int i=n-2;i>=0;i--){
            for(int j=1;j<m;j++){
                prev0[j] = (prev0[j]+prev0[j-1])%mod;
                prev1[j] = (prev1[j]+prev1[j-1])%mod;
            }

            for(int j=0;j<m;j++){
                curr0[j] = (prev1[m-1]-prev1[j]+mod)%mod;
                curr1[j] = j==0?0:prev0[j-1];
            }

            prev0 = curr0;
            prev1 = curr1;
        }

        int ans = 0;

        for(int i=0;i<m;i++){
            ans = (ans+prev0[i])%mod;
            ans = (ans+prev1[i])%mod;
        }

        return ans;
    }
};
