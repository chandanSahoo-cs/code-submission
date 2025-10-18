class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int curr = 1e9;
        int prof = 0;
        for(int i=0;i<n;i++){
            prof = max(prof,prices[i]-curr);
            curr = min(curr,prices[i]);
        }

        return prof;
    }
};
