class Solution {
public:
    vector<vector<int>>ans;

    void rec(vector<int>&cand,int tr, int i, vector<int>&temp, int ignore){
        int n = cand.size();

        if(i==n && tr==0){
            ans.push_back(temp);
            return;
        }

        if(i==n || tr<0) return;

        if(cand[i]==ignore){
            rec(cand,tr,i+1,temp,ignore);
            return;
        }

        rec(cand,tr,i+1,temp,cand[i]);
        temp.push_back(cand[i]);
        rec(cand,tr-cand[i],i+1,temp,51);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        rec(candidates,target,0,temp,51);

        return ans;    
    }
};
