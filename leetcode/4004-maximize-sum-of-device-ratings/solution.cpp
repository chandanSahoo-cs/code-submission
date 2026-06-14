#define ll long long
class Solution {
public:
    ll maxRatings(vector<vector<int>>& units) {
        int n = units.size(), m = units[0].size();

        ll sum = 0;
        int leftMn = INT_MAX, rightMn = INT_MAX;

        for(int i=0;i<n;i++){
            int mn = INT_MAX, scndMn = INT_MAX;

            for(int j=0;j<m;j++){
                if(units[i][j]<=mn){
                    scndMn = mn;
                    mn = units[i][j];
                }else if(units[i][j]<=scndMn){
                    scndMn = units[i][j];
                }
            }

            if(scndMn==INT_MAX){
                sum+=mn;
            }else{
                sum+=scndMn;
                leftMn = min(leftMn,mn);
                rightMn = min(rightMn,scndMn);
            }
        }

        return sum-(rightMn==INT_MAX?0:rightMn)+(leftMn==INT_MAX?0:leftMn);
    }
};
