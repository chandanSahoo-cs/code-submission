class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;


        for(int i=1;i<n;i++){
            int x = abs(points[i-1][0]-points[i][0]);
            int y = abs(points[i-1][1]-points[i][1]);

            ans+=min(x,y);
            ans+=max(x,y)-min(x,y);
        }

        return ans;
    }
};
