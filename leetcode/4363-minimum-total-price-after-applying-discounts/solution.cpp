class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size(), m = discounts.size();

        sort(prices.begin(),prices.end(),greater());
        sort(discounts.begin(),discounts.end(),greater());

        int i = 0;
        double sum = 0;

        for(int j=0;j<m;j++){
            if(i==n) break;
            int p = prices[i++];
            int d = discounts[j];

            sum+=(p*(100.0-d))/100.0; 
        }

        while(i<n){
            sum+=prices[i++];
        }

        return sum;
    }
};
