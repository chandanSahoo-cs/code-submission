const int mod = 1e9+7;

class Fancy {
    int binExp(int base,int exp){
        int res = 1;

        while(exp){
            if(exp&1){
                res=(res*1LL*base)%mod;
            }
            base = (base*1LL*base)%mod;
            exp>>=1;
        }

        return res;
    }

public:
    vector<int>store;
    vector<pair<int,int>>change;
    int sum,mul;

    Fancy() {
        sum=0;
        mul=1;
    }
    
    void append(int val) {
        change.push_back({sum,mul});
        store.push_back(val);
    }
    
    void addAll(int inc) {
        sum = (sum+inc)%mod;
    }
    
    void multAll(int m) {
        mul = (mul*1LL*m)%mod;
        sum = (sum*1LL*m)%mod;
    }
    
    int getIndex(int idx) {
        if(store.size()<idx+1) return -1;

        int val = store[idx];

        auto [cSum, cMul] = change[idx];

        int nMul = (mul*1LL*binExp(cMul,mod-2))%mod;

        int nSum = (sum-(cSum*1LL*nMul)%mod+mod)%mod;

        return (((val*1LL*nMul)%mod)+nSum)%mod;
    }

    /*

    (5+2)*3
    5*3+2*3

    (5+2)*3+4
    5*3+2*3+4

    ((5+2)*3+4)*6
    (5*3+2*3+4)*6
    5*18+2*18+24

    sum1*mul1*mul2+sum*2*mul2+sum3

    */
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
