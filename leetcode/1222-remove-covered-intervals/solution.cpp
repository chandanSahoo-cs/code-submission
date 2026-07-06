class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(),intervals.end(),[&](vector<int>&v1, vector<int>&v2){
            if(v1[0]==v2[0]) return v1[1]>v2[1];
            return v1[0]<v2[0];
        });

        int c = intervals[0][0], d = intervals[0][1];
        int cnt = 1;

        for(int i=1;i<n;i++){
            int a = intervals[i][0], b = intervals[i][1];

            if(c>a || b>d){
                cnt++;
                c=a,d=b;
            }
        }

        return cnt;
    }
};
