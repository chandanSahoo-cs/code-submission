class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int mx = *max_element(costs.begin(),costs.end());

        vector<int>freq(mx+1);

        for(auto ele:costs){
            freq[ele]++;
        }

        vector<int>nCosts;

        for(int i=1;i<=mx;i++){
            while(freq[i]--){
                nCosts.push_back(i);
            }
        }


        for(int i=0;i<n;i++){
            if(coins-nCosts[i]<0) return i;
            coins-=nCosts[i];
        }

        return n;
    }
};
