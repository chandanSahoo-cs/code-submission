class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        
        vector<pair<double,double>>vp;

        double totSum=0;

        for(auto &ele:squares){
            int x = ele[0];
            int y = ele[1];
            int l = ele[2];

            totSum+=l*1LL*l;

            vp.push_back({ele[1],l});
            vp.push_back({ele[1]+ele[2],-l});
        }

        sort(vp.begin(),vp.end());

        double reqSum = totSum/(double)2;
        double currSum = 0;

        int sz = vp.size();
        int i=0;
        double x = 0;

        while(i<sz-1){
            auto [y1,l] = vp[i];

            while(i<sz-1 && y1==vp[i].first){
                x+=vp[i].second;
                i++;
            }
            
            double y2 = vp[i].first;

            double tempSum = (y2-y1)*x;

            if(currSum+tempSum>=reqSum){
                double tr = reqSum-currSum;
                return y1+tr/x;
            }else currSum+=tempSum;
        }

        return 0;
    }
};
