class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        if (matrix.size() == matrix[0].size()) {
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix.size(); j++) {
                    if (j > i) {
                        swap(matrix[i][j], matrix[j][i]);
                    }
                }
            }
        } else {
            vector<vector<int>> transposed(matrix[0].size(), vector<int>(matrix.size()));
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    transposed[j][i] = matrix[i][j];
                }
            }
            matrix = transposed;
        }
        
        return matrix;
    }
};


