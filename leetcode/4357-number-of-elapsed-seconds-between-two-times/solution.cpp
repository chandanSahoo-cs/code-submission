class Solution {
public:
    int secondsBetweenTimes(string st, string et) {
        int strtHr = (st[0]-'0')*10+(st[1]-'0');
        int endHr = (et[0]-'0')*10+(et[1]-'0');
        
        int strtMn = (st[3]-'0')*10+(st[4]-'0');
        int endMn = (et[3]-'0')*10+(et[4]-'0');

        int strtSc = (st[6]-'0')*10+(st[7]-'0');
        int endSc = (et[6]-'0')*10+(et[7]-'0');

        int strt = strtHr*3600+strtMn*60+strtSc;
        int end = endHr*3600+endMn*60+endSc;


        return end-strt;
    }
};
