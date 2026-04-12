class Solution {
public:
    double getAngle(double x){
        return acos(max(-1.0, min(1.0, x))) * (180.0 / M_PI);
    }
    vector<double> internalAngles(vector<int>& sides) {

        int a = sides[0], b = sides[1], c = sides[2];

        if(a+b<=c || b+c<=a || a+c<=b) return {};

        int a2 = a*a, b2 = b*b, c2 = c*c;

        double angl1 = getAngle((b2+c2-a2)/(2.0*b*c));
        double angl2 = getAngle((a2+c2-b2)/(2.0*a*c));
        double angl3 = getAngle((a2+b2-c2)/(2.0*a*b));

        vector<double>ans = {angl1,angl2,180-angl1-angl2};
        sort(ans.begin(),ans.end());
        return ans;
    }
};
