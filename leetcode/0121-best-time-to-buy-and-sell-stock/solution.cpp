class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int curr=prices[0];
        int mx=0;

        for(int i=1;i<n;i++){
            mx = max(prices[i]-curr,mx);
            curr = min(curr,prices[i]);
        }

        return mx;
    }
};
