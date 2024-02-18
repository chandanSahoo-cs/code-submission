class Solution {
    #define ll long long
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        for(ll i=0;i<intervals.size();i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        vector<int>ans(intervals.size());
        for(ll i=0;i<intervals.size();i++){
            ll s=0,e=intervals.size()-1;
            ll temp=-1;
            while(s<=e){
                ll m=s+(e-s)/2;
                if(intervals[m][0]==intervals[i][1]){
                    temp=intervals[m][2];
                    break;
                }
                else if(intervals[m][0]>intervals[i][1]) {
                    temp=intervals[m][2];
                    e=m-1;
                }
                else s=m+1;
            }
            ans[intervals[i][2]]=temp;
        }
        return ans;
    }
};
