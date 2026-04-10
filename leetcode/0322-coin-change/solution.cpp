class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>curr(amount+1),next(amount+1,1e5);

        for(int i=n-1;i>=0;i--){
            for(int amt=0;amt<=amount;amt++){
                if(amt>0){
                    int p = amt-coins[i]<0?1e5:1+curr[amt-coins[i]];
                    int np = next[amt];

                    curr[amt] = min(p,np);
                }
            }

            next = curr;
        }

        return next[amount]>=1e5?-1:next[amount];
    }
};
