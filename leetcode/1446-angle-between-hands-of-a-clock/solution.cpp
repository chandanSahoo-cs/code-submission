class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = minutes*6;
        double hourAngle = hour*30+0.5*minutes;

        double diff = abs(minAngle-hourAngle);
        return min(360-diff,diff);
    }
};
