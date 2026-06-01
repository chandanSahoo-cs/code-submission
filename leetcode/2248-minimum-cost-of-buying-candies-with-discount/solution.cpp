class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end());

        int sum = 0, cnt = 0;

        for(int i=n-1;i>=0;i--){
            if(cnt<2){
                sum+=cost[i];
                cnt++;
            }else cnt=0;
        }

        return sum;
    }
};
