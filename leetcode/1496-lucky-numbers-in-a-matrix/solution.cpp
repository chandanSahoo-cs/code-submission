class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            auto minValue=min_element(matrix[i].begin(),matrix[i].end());
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==*minValue){
                    int row=0;
                    bool flag=true;
                    while(row<matrix.size()){
                        if(matrix[row][j]>*minValue && row!=i){
                            flag=false;
                            
                        }
                        row++;
                    }
                    if(flag) return {*minValue};
                }
            }
        }
        return {};
    }
};
