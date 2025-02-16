class Solution {
public:
    vector<vector<int>>ans;
    void  fill(vector<int> &a,int t,int i,vector<int>&s, int last){
        if(t==0){
            ans.push_back(s);
            return;
        }
        if(a.size()==i) return;
        if(t<0) return; 
        if(a[i]==last) {
            fill(a,t,i+1,s,a[i]);
            return;
        };
        s.push_back(a[i]);
        fill(a,t-a[i],i+1,s,-1);
        s.pop_back();
        fill(a,t,i+1,s,a[i]);
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        sort(a.begin(),a.end());
        vector<int>s;
        fill(a,t,0,s,-1);

        return ans;
    }
};
