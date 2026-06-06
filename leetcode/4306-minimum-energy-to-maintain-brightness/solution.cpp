#define ll long long

class Solution {
public:

    bool overlap(int l1, int r1, int l2, int r2){
        if(l2<=r1 || r2<=l1) return true;
        return false;
    }

    ll minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        
        ll ans = 0;

        int req = (brightness+2)/3;

        sort(intervals.begin(),intervals.end());

        int m = intervals.size();

        vector<vector<int>>fixed;
        fixed.push_back(intervals[0]);


        for(int i=1;i<m;i++){
            int l1 = fixed.back()[0], r1 = fixed.back()[1];
            int l2 = intervals[i][0], r2 = intervals[i][1];

            if(overlap(l1,r1,l2,r2)){
                fixed.pop_back();
                fixed.push_back({min(l1,l2),max(r1,r2)});
            }else fixed.push_back({l2,r2});
        }

        for(auto ele:fixed){
            int l = ele[0], r = ele[1];

            ll len = r-l+1;

            ans+= req*len;
        }

        return ans;
    }
};

/*
0 0 0 0 0 0
1 0 0 1 0 0

0 1 0 0 1 0 0 1 0 0 1 0 0 1

if l%3==0, then we need one more
if l%3==1, then good
if l%3==2, then good
*/
