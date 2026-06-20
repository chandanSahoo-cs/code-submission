class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        if(r.size()==0) return n-1;

        r.push_back({1,0});
        r.push_back({n,n-1});

        int m = r.size();
        sort(r.begin(),r.end());

        /*
        max height = min(currHeight,prevHeight+distance between the two)
        */

        for(int i=1;i<m;i++){
            r[i][1] = min(r[i][1],r[i-1][1]+(r[i][0]-r[i-1][0]));
        }

        for(int i=m-2;i>=0;i--){
            r[i][1] = min(r[i][1],r[i+1][1]+(r[i+1][0]-r[i][0]));
        }

        int ans = 0;

        for(int i=0;i<m-1;i++){
            int largest = ((r[i+1][0]-r[i][0])+r[i][1]+r[i+1][1])>>1;
            ans = max(ans,largest);
        }

        return ans;
    }
};
