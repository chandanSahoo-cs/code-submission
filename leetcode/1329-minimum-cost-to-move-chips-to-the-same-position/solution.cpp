class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        vector<int>values(2,0);
        for(auto p:position){
            values[p%2]++;
        }
        return min(values[1],values[0]);
    }
};
