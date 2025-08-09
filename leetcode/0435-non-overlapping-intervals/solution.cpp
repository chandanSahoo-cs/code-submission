class Solution {
public:

    bool check(pair<int,int>& x, pair<int,int> &y){
        return x.first<y.second && y.first<x.second;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        vector<pair<int,int>>vp;

        for(auto ele:intervals){
            vp.push_back({ele[0],ele[1]});
        }

        sort(vp.begin(),vp.end(),[&](pair<int,int> &v1, pair<int,int> &v2){
            return v1.second<v2.second;
        });

        int ptr=-1;
        int cnt=0;

        int n = vp.size();

        for(int i=0;i<n;i++){
            if(i==0) {
                ptr=i;
            }
            else {
                if(!check(vp[ptr],vp[i])){
                    ptr=i;;
                }else cnt++;
            }
        }
        return cnt;
    }

};
