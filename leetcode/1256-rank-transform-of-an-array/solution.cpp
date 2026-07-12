class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>foo(n);
        iota(foo.begin(),foo.end(),0);

        sort(foo.begin(),foo.end(),[&](int i, int j){
            return arr[i]<arr[j];
        });

        vector<int>ans(n);
        int rank = 0;

        for(int i=0;i<n;i++){
            if(i!=0 && arr[foo[i]]==arr[foo[i-1]]) ans[foo[i]]=rank;
            else{
                rank++;
                ans[foo[i]] = rank;
            }
        }

        return ans;
    }
};
