class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int mn = INT_MAX;

        int tx = target[0];
        int ty = target[1];


        int i = 0;
        for(auto &ele:drones){
            int x = ele[0], y = ele[1], range = ele[2];
            int dist = abs(x-tx)+abs(y-ty);

            if(dist<=range){
                if(mn>dist){
                    ans = i;
                    mn = dist;
                }
            }
            i++;
        }

        return ans;
    }
};
