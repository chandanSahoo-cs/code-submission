class Solution {
public:
    bool check(vector<int>x, vector<int>y){
        return (x[0]<=y[1] && y[0]<=x[1]);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans = {intervals[0]};

        for(int i=1;i<n;i++){
            vector<int>x = ans.back();
            vector<int>y = intervals[i];
            if(check(x,y)){
                int mn = min(x[0],y[0]);
                int mx = max(x[1],y[1]);
                ans.pop_back();
                ans.push_back({mn,mx});
            }else{
                ans.push_back(y);
            }
        }

        return ans;
    }
};
