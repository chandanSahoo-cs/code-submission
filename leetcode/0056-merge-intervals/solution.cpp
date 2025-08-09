class Solution {
public:
    bool check(vector<int>&x,vector<int>&y){
        return x[0]<=y[1] && y[0]<=x[1];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());

        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            if(i==0){
                ans.push_back(intervals[i]);
            }else{
                if(check(ans.back(),intervals[i])){
                    int x1=ans.back()[0];
                    int x2=ans.back()[1];
                    ans.pop_back();
                    ans.push_back({min(x1,intervals[i][0]),max(intervals[i][1],x2)});
                }else{
                    ans.push_back(intervals[i]);
                } 
            }
        }

        return ans;    
    }
};
