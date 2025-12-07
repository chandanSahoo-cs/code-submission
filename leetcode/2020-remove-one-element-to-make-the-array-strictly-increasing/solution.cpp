#define ll int
class Solution {
public:
    bool check(ll n, vector<ll>&a, ll k){
        for(int i=1;i<n;i++){
            if(i==k) continue;
            int cmp = i-1;

            if(cmp==k){
                cmp=k-1;
            }

            if(cmp>=0 && a[i]<=a[cmp]){
                return false;
            }
        }
        return true;
    }

    bool canBeIncreasing(vector<int>& a) {
        ll n = a.size();
        ll k=-1,l=-1;

        for(int i=1;i<n;i++) {
            if(a[i]<=a[i-1]){
                k=i;
                l=i-1;
                break;
            }
        }

        if(k==-1){
            return true;
        }

        cout<<k<<" "<<l<<"\n";

        cout<<check(n,a,k)<<"\n";

        if(check(n,a,k) || check(n,a,l)){
            return true;
        }else return false;
    }
};
