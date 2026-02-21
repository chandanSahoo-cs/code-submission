class Solution {
public:

    int countPrimeSetBits(int left, int right) {
        
        vector<int>prime(32);
        prime[0]=prime[1]=1;

        for(int i=2;i<32;i++){
            if(prime[i]) continue;
            
            for(int j=2*i;j<32;j+=i){
                prime[j]=1;
            }
        }

        int cnt = 0;

        for(int i=left;i<=right;i++){
            if(!prime[__builtin_popcount(i)]) cnt++;
        }

        return cnt;
    }
};
