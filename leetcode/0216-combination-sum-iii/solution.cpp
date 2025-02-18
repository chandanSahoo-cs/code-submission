class Solution {
public:
    vector<vector<int>>ans;
    void fill(int k, int n, vector<int>&s, int e){

        if(s.size()==k){
            if(n==0){
                ans.push_back(s);
            }

            return;
        }
        if(e==10) return;

        s.push_back(e);
        fill(k,n-e,s,e+1);
        s.pop_back();
        fill(k,n,s,e+1);
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>s;
        fill(k,n,s,1);
        return ans;
    }
};
