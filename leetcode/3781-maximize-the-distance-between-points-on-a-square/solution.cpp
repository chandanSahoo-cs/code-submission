#define ll long long

class Solution {
public:

    bool check(vector<ll>& store, int m, int k, int side){

        for(auto strt:store){
            ll curr = strt;
            ll end = strt+4LL*side-m;

            bool flag = true;
            for(int i=0;i<k-1;i++){
                auto it = lower_bound(store.begin(),store.end(),curr+m);
                if(it==store.end() || *it>end){
                    flag = false;
                    break;
                }
                curr = *it;
            }

            if(flag) return true;
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll>store;

        for(auto &ele:points){
            int x = ele[0], y = ele[1];

            if(x==0){
                store.push_back(y);
            }else if(x==side){
                store.push_back(3LL*side-y);
            }else if(y==0){
                store.push_back(4LL*side-x);
            }else if(y==side){
                store.push_back(side+x);
            }
        }

        sort(store.begin(),store.end());

        int l = 1, r = side;
        int ans = l;
        while(l<=r){
            int m = l+(r-l)/2;

            if(check(store,m,k,side)){
                ans = m;
                l = m+1;
            }else{
                r = m-1;
            }
        }

        return ans;
    }
};
