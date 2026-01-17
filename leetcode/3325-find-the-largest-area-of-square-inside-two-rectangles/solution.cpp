#define ll long long

class Solution {
public:

    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        int n = bl.size();

        ll mx = 0;

        for(int i=0;i<n;i++){
            ll rect1_l = bl[i][0];
            ll rect1_r = tr[i][0];
            
            ll rect1_d = bl[i][1];
            ll rect1_u = tr[i][1];

            for(int j=i+1;j<n;j++){

                ll rect2_l = bl[j][0];
                ll rect2_r = tr[j][0];
                
                ll rect2_d = bl[j][1];
                ll rect2_u = tr[j][1];

                ll side1 = min(rect1_r,rect2_r)-max(rect1_l,rect2_l);
                ll side2 = min(rect1_u,rect2_u)-max(rect1_d,rect2_d);

                if(side1>0 && side2>0){
                    ll mn = min(side1,side2);
                    mx = max(mx,mn);
                }

            }
        }

        return mx*mx;
    }
};
