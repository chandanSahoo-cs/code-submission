class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        for(int i=0;i<n;i++){
            int tempi=i;
            int tempj=0;
            tempi++;
            tempj++;
            while(tempi<n && tempj<m){
                if(a[tempi][tempj]!=a[tempi-1][tempj-1]){
                    // cout<<tempi<<" "<<tempj<<" "<<a[tempi][tempj]<<" "<<a[tempi-1][tempj-1]<<"\n";
                    return false;
                }
                tempi++;
                tempj++;
            }
        }

        for(int j=0;j<m;j++){
            int tempj=j;
            int tempi=0;
            tempi++;
            tempj++;
            while(tempi<n && tempj<m){
                if(a[tempi][tempj]!=a[tempi-1][tempj-1]){
                    // cout<<tempi<<" "<<tempj<<" "<<a[tempi][tempj]<<" "<<a[tempi-1][tempj-1]<<"\n";
                    return false;
                }
                tempi++;
                tempj++;
            }
        }

        return true;
    }
};
