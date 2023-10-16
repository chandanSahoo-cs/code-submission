class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>output(n,vector<int>(n,0));
        int num=1;
        int rowBegin=0,rowEnd=n-1,columnBegin=0,columnEnd=n-1;
        while(num<=n*n){
            for(int i=columnBegin;i<=columnEnd;i++){
                output[rowBegin][i]=num++;
            }
            rowBegin++;
            for(int i=rowBegin;i<=rowEnd;i++){
                output[i][columnEnd]=num++;
            }
            columnEnd--;
            if(rowBegin<=rowEnd){
                for(int i=columnEnd;i>=columnBegin;i--){
                    output[rowEnd][i]=num++;
                }
                rowEnd--;
            }
            if(columnBegin<=columnEnd){
                for(int i=rowEnd;i>=rowBegin;i--){
                    output[i][columnBegin]=num++;
                }
                columnBegin++;
            }
        }
        return output;
    }
};
