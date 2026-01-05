class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negCnt = 0;
        long long sum = 0;
        int mn = INT_MAX;

        for(auto row:matrix){
            for(auto ele:row){
                if(ele<0) negCnt++;

                sum+=1LL*abs(ele);
                mn = min(mn,abs(ele));
            }
        }

        if(negCnt%2) return sum-2*mn;
        else return sum;
    }
};
