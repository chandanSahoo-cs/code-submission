class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& m) {
        int n = m.size();
        int negCnt=0;
        long long ans=0;
        int mn = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]<0) negCnt++;
                ans+=abs(m[i][j]);
                mn=min(mn,abs(m[i][j]));
            }
        }
        if(negCnt%2){
            ans-=2*mn;
        }
        return ans;
    }
};
