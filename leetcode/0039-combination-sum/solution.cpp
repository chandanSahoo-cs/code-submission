class Solution {
public:
    vector<vector<int>>ans;

    void rec(vector<int>& cand, int tr, int i, vector<int>&temp){
        int n = cand.size();
        if(tr==0 && i==n){
            ans.push_back(temp);
            return;
        }

        if(tr<0 || i==n) return;

        rec(cand,tr,i+1,temp);
        temp.push_back(cand[i]);
        rec(cand,tr-cand[i],i,temp);
        temp.pop_back();

        return;

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        rec(candidates,target, 0, temp);

        return ans;    
    }
};
