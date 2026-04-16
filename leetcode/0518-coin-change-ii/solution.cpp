class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int>curr(amount+1),next(amount+1);

        next[0]=curr[0]=1;

        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                curr[j] = (j-coins[i]>=0?curr[j-coins[i]]:0)+next[j];
            }
            next = curr;
        }

        return next[amount];
    }
};
