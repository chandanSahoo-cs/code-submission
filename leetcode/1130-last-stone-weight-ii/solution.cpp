class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(),stones.end(),0);
        int req = sum/2;

        vector<int>curr(req+1), next(req+1);


        for(int i=n-1;i>=0;i--){
            for(int j=req;j>=0;j--){
                int take = (stones[i]+j<=req)?stones[i]+next[j+stones[i]]:0;
                int nTake= next[j];

                curr[j] = max(take,nTake);
            }

            next = curr;
        }

        cout<<next[0];

        return sum-2*next[0];
    }
};
