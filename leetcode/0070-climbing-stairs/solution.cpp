class Solution {
public:
    int climbStairs(int n) {
        int frstTrm=0;
        int scndTrm=1;
        int endTrm;
        for(int i=0;i<n;i++){
            endTrm=frstTrm+scndTrm;
            frstTrm=scndTrm;
            scndTrm=endTrm;
        }
        return scndTrm;
    }
};
