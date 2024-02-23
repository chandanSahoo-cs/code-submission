class Solution {
    #define ll long long
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ll s=1;
        ll e=*max_element(piles.begin(),piles.end());
        ll n=piles.size();
        while(s<=e){
            ll m=s+(e-s)/2;
            ll sum=0;
            for(auto &ele:piles) sum+=(ele+m-1)/m;
            if(sum>h) s=m+1;
            else e=m-1;
        }
        return s;
    }
};
