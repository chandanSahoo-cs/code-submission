class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>output;
        int rowBegin=0,rowEnd=matrix.size()-1,columnBegin=0,columnEnd=matrix[0].size()-1;
        while(rowBegin<=rowEnd and columnBegin<=columnEnd){
            for(int i=columnBegin;i<=columnEnd;i++){
                output.push_back(matrix[rowBegin][i]);
            }
            rowBegin++;
            for(int i=rowBegin;i<=rowEnd;i++){
                output.push_back(matrix[i][columnEnd]);
            }
            columnEnd--;
            if(rowBegin<=rowEnd){
                for(int i=columnEnd;i>=columnBegin;i-- ){
                    output.push_back(matrix[rowEnd][i]);
                }
                rowEnd--;
            }
            if(columnBegin<=columnEnd){
                for(int i=rowEnd;i>=rowBegin;i--){
                    output.push_back(matrix[i][columnBegin]);
                }
                columnBegin++;
            }
        }
        return output;
    }
};
