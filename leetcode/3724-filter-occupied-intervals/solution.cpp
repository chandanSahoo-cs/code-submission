class Solution {
public:

    bool overlap(int x1, int y1, int x2, int y2){
        if((x1<=y2 && y1+1>=x2 )) return true;
        return false;
    }
    
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occ, int fStart, int fEnd) {
        vector<vector<int>>a;

        for(auto &ele:occ){
            int strt = ele[0];
            int end = ele[1];

            if(strt>=fStart && end<=fEnd) continue;
            
            if(strt<fStart && end>fEnd){
                a.push_back({strt,fStart-1});
                a.push_back({fEnd+1,end});
                continue;
            }
                
            if(strt>=fStart && strt<=fEnd) strt = fEnd+1;
            if(end>=fStart && end<=fEnd) end = fStart-1;

            a.push_back({strt,end});
        }
        
        int n = a.size();

        sort(a.begin(),a.end());
        
        vector<vector<int>>ans;
        if(a.size()>0) ans.push_back(a[0]);
        
        for(int i=1;i<n;i++){
            int x1 = ans.back()[0], y1 = ans.back()[1];
            int x2 = a[i][0], y2 = a[i][1];
            
            if(overlap(x1,y1,x2,y2)){
                ans.pop_back();
                ans.push_back({min(x1,x2),max(y1,y2)});
            }else ans.push_back({x2,y2});
        }

        return ans;
    }
};
