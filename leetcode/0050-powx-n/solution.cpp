#define ll long long

class Solution {
public:

    double Pow(double x, ll n, map<ll,double> &store){
        // cout<<n<<"\n";
        if(n==0) return 1;
        if(n==1) return x;
        if(store.find(n)!=store.end()) return store[n];
        double p = Pow(x,n/2,store);
        if(n%2!=0){
            return store[n] = x*p*p;
        }
        else{
            return store[n] = p*p;
        }
    }

    double myPow(double x, int n) {
        ll n1 = n;
        map<ll,double>store;
        if(n1<0){
            return 1/Pow(x,abs(n1),store);
        }
        else return Pow(x,n1,store);
    }
};
