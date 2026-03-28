const int mod = 1e9+7;

class Solution {
public:
    int fact[100005], invFact[100005];

    int binExp(int base, int exp){
        int res = 1;
    
        while(exp>0){
            if(exp&1){
                res = (res*1LL*base)%mod;
            }
            base = (base*1LL*base)%mod;
            exp>>=1;
        }
    
        return res;
    }

    void precompute(){
        fact[0]=1;

        for(int i=1;i<100005;i++){
            fact[i] = (fact[i-1]*1LL*i)%mod;
        }

        invFact[100004] = binExp(fact[100004],mod-2);
        /*
        (i+1)! = (i)!*(i+1)
        
        inverse on both sides
        ((i+1)!)^-1 = ((i)!)^-1*((i+1)^-1);
        
        reordering eqaution
        ((i)!)^-1 = ((i+1)!)^-1*(i+1)
        */

        for(int i=100003;i>=0;i--){
            invFact[i] = (invFact[i+1]*1LL*(i+1))%mod;
        }

        return;
    }

    int ncr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return((fact[n] *1LL* invFact[r] % mod) *1LL* invFact[n-r] % mod);
    }
    
    int countVisiblePeople(int n, int pos, int k) {

        int left = pos;
        int right = n-pos-1;
        precompute();


        // if(left>right) swap(left,right);

        long long ans = 0;
        
        for(int i=0;i<=min(left,k);i++){
            ans = (ans+(ncr(left,i)*1LL*ncr(right,k-i))%mod)%mod;    
        }

        return (2*ans)%mod;
    }
};
