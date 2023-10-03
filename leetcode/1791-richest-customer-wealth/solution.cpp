class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxValue=INT_MIN;
        for(int i=0;i<accounts.size();i++){
            int sum=0;
            int j=1;
            while(j<accounts[i].size()){
                accounts[i][j]+=accounts[i][j-1];
                j++;
            }
            maxValue=max(maxValue,accounts[i][j-1]);
        }
        return maxValue;
    }
};
