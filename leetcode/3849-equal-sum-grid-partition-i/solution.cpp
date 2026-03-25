#define ll long long

class Solution {
public:
    bool equalPart(vector<ll>&a){
        int n = a.size();
        ll sum = accumulate(a.begin(),a.end(),0LL);

        if(sum&1) return false;

        ll curr = 0;

        for(int i=0;i<n;i++){
            curr+=a[i];

            if(curr == sum-curr) return true;
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<ll>hr(m), vr(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vr[i]+=grid[i][j];
                hr[j]+=grid[i][j];
            }
        }

        return equalPart(hr) | equalPart(vr);
    }
};
