class Solution {
public:
    int calc(vector<int>&fStartTime, vector<int>&fDuration, vector<int>&sStartTime, vector<int>&sDuration){
        int n = fStartTime.size(), m = sStartTime.size();

        int finish1 = INT_MAX;

        for(int i=0;i<n;i++){
            finish1 = min(finish1, fStartTime[i]+fDuration[i]);
        }

        int finish2 = INT_MAX;

        for(int i=0;i<m;i++){
            int part = max(finish1,sStartTime[i]);
            finish2 = min(finish2,part+sDuration[i]);
        }

        return finish2;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ltw = calc(landStartTime,landDuration,waterStartTime,waterDuration);
        int wtl = calc(waterStartTime,waterDuration,landStartTime,landDuration);

        return min(ltw,wtl);
    }
};
