#define ll long long
class Solution {
public:
    bool compute(int n, int maxSum, int index, int m){
        ll al = max(m-index,1);
        ll nl = (m-al+1);
        ll suml = (nl*(al+m))/2;

        ll ar = max(m-(n-1-index),1);
        ll nr = (m-ar+1);
        ll sumr = (nr*(ar+m))/2;

        ll totSum = suml+sumr+n-(nr+nl-1)-m;

        return totSum<=maxSum;
    }

    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = 1e9;
        int ans = l;

        while(l<=r){
            int m = l+(r-l)/2;

            if(compute(n,maxSum,index,m)){
                ans = m;
                l = m+1;
            }else{
                r=m-1;
            }
        }

        return ans;
    }
};
