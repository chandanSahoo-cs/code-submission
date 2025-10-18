class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();

        vector<int>prev(5);
        vector<int>curr(5);

        for(int i=n-1;i>=0;i--){
            for(int t=3;t>=0;t--){
                int ans = 0;
                if(t%2==0){
                    ans = max(prev[t],-a[i]+prev[t+1]);
                }else{
                    ans = max(a[i]+prev[t+1],prev[t]);
                }
                curr[t]=ans; 
            }
            prev = curr;
        }

        return prev[0];
    }
};
