class Solution {
public:
    int countPrimes(int n) {
        vector<int>prime(n,0);

        for(int i=2;i<n;i++){
            if(prime[i]) continue;

            for(int j=2*i;j<n;j+=i){
                prime[j]=1;
            }
        }

        int ans=0;

        for(int i=2;i<n;i++){
            if(!prime[i]) ans++;
        }

        return ans;
    }
};
