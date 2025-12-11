#define ll long long

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        ll tn = n*n;

        int org = tn*(tn+1)/2;
        ll orgSqr = (tn*(tn+1)*(2*tn+1))/6;

        int curr = 0;
        ll currSqr = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                curr+=grid[i][j];
                currSqr+=grid[i][j]*grid[i][j];
            }
        }

        int z = (orgSqr-currSqr)/(org-curr);
        int x = (z+org-curr)/2;
        int y = x+curr-org;

        return {y,x};
    }
};
