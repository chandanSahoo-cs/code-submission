class Solution {
    #define ll long long
public:
    int countNegatives(vector<vector<int>>& grid) {
        ll row=grid.size();
        ll col=grid[0].size();
        ll negCnt=0;
        // ll s=0,e=col-1;
        for(ll i=0;i<row;i++){
            ll s=0,e=col-1;
            while(s<=e){
                ll m=s+(e-s)/2;
                if(grid[i][m]>=0) s=m+1;
                else e=m-1;
            }
            if (e==col+1) continue;
            negCnt+=col-e-1;          
        }
        return negCnt;
    }
};
