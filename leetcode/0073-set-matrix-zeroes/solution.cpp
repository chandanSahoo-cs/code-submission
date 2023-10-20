class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> storei;
        vector<int> storej;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    storei.push_back(i);
                    storej.push_back(j);
                }
            }
        }
        
        // Set rows to zero
        for (int i = 0; i < storei.size(); i++) {
            for (int j = 0; j < cols; j++) {
                matrix[storei[i]][j] = 0;
            }
        }
        
        // Set columns to zero
        for (int i = 0; i < storej.size(); i++) {
            for (int j = 0; j < rows; j++) {
                matrix[j][storej[i]] = 0;
            }
        }
    }
};

