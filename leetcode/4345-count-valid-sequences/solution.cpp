#define ll long long
const int mod = 1e9+7;
const int N = 1e6+5;

ll fact[N], invFact[N];

ll binExp(ll base, ll exp){
    ll ans = 1;
    while(exp){
        if(exp&1){
            ans = (ans*base)%mod;
        }
        base=(base*base)%mod;
        exp>>=1;
    }

    return ans;
}

void init(int n){
    fact[0] = 1;

    for(int i=1;i<=n;i++){
        fact[i] = (i*fact[i-1])%mod;
    }

    invFact[n] = binExp(fact[n],mod-2);

    for(int i=n-1;i>=0;i--){
        invFact[i] = (invFact[i+1]*(i+1))%mod;
    }

    return;
}

ll nCr(int n, int r){
    if(r<0 || r>n) return 0;

    return ((fact[n]*invFact[r])%mod*invFact[n-r])%mod;
}

class Solution {
public:
    /*
    star and bars
    - C(n+k-1,k-1) // normally
    - C(n-k+k-1,k-1) => C(n-1,k-1) // when there should be atleast 1 element in each group
    
    # For odd number of elements in each group
    - number of elements in each group is x = 2*y+1 (where y can be 0,1,2,3...)
    - x1+x2+...xk = n;
    - 2(y1+y2+....yk)+k = n (subsituting the value)
    - y1+y2+....yk = (n-k)/2
    - so in total we have (n-k)/2 elements now (if n-k is even, in case of odd, no combination is possible), instead of n
    - so the formula changes to C((n-k)/2+k-1,k-1) => C((n+k-2)/2,k-1) => C((n+k)/2-1,k-1)
    */


    int countValidSequences(int n, int k) {
        init(n+k);

        int total = nCr(n-1,k-1);
        
        if((n-k)&1) return total;

        int totalOdd= nCr(((n+k)/2)-1,k-1);

        return (total-totalOdd+mod)%mod; 
    }
};
