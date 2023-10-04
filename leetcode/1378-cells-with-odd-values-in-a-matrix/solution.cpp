class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int>rowCount(m,0);
        vector<int>colCount(n,0);
        for(auto ele:indices){
            rowCount[ele[0]]++;
            colCount[ele[1]]++;
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cell=rowCount[i]+colCount[j];
                if(cell%2!=0) count++;
            }
        }
        return count;
    }
};

