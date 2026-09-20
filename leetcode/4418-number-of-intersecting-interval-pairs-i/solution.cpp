class Solution {
public:
    bool check(int l1, int r1, int l2, int r2){
        return l1<=r2 && l2<=r1;
    }

    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cnt+=check(intervals[i][0],intervals[i][1],intervals[j][0],intervals[j][1]);
            }
        }

        return cnt;
    }
};
