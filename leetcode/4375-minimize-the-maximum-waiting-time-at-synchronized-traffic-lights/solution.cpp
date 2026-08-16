class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int mx = *max_element(lights.begin(),lights.end());
        int ans = 0;
        for(auto ele:arrivalTime){
            ele%=period;
            if(ele>=mx){
                ans = max(ans,period-ele); 
            }
        }

        return ans;
    }
};
