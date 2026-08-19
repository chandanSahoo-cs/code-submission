class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int m = rs.size();
        sort(rs.begin(),rs.end(),[&](vector<int>&a, vector<int>&b){
            return a[0]<b[0];
        });

        int total = n*2;

        int i = 0;

        while(i<m){
            vector<bool>mark(11,true);
            do{
                mark[rs[i][1]] = false;
                i++;
            }while(i<m && rs[i][0]==rs[i-1][0]);

            total-=2;

            if(mark[2] && mark[3] && mark[4] && mark[5] && mark[6] && mark[7] && mark[8] && mark[9]) total+=2;
            else if(mark[2] && mark[3] && mark[4] && mark[5]) total++;
            else if(mark[4] && mark[5] && mark[6] && mark[7]) total++;
            else if(mark[6] && mark[7] && mark[8] && mark[9]) total++;
        }

        return total;
    }
};
