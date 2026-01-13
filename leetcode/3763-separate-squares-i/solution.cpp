class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double l=1e9, r=0;
        double totalArea=0;

        for(auto &ele:squares){
            double y = ele[1];
            double side = ele[2];
            l = min(y,l);
            r = max(y+side,r);
            totalArea+=side*side;
        }

        double target = totalArea/2.0;
        double ans = r;

        for(int i=0;i<50;i++){
            double m = l+(r-l)/2;

            double upper=0;

            for(auto &ele:squares){
                double y=ele[1],side=ele[2];

                double h2 = side+y-m;

                if(h2>0){
                    if(side<h2) h2=side;
                    upper+=side*h2;
                }
            }

            if(upper<=target){
                ans = min(ans,m);
                r=m;
            }
            else l=m;
        }

        return ans;
    }
};
