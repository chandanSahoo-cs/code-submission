class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ans = arr;
        sort(ans.begin(),ans.end(),[&](int i,int j){
            int seti = __builtin_popcount(i);
            int setj = __builtin_popcount(j);
            if( seti==setj) return i<j;
            return seti<setj;
        });

        return ans;
    }
};
