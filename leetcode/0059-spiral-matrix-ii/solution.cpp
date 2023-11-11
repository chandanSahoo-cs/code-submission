class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rowBegin = 0;
        int colBegin = 0;
        int rowEnd = n;
        int colEnd = n;
        int value = 1; // Start from 1, as you want to fill the matrix with consecutive numbers
        vector<vector<int>> output(n, vector<int>(n, 0)); // Initialize the matrix with zeros

        while (rowBegin < rowEnd && colBegin < colEnd) {
            // Traverse the top row
            for (int i = colBegin; i < colEnd; ++i) {
                output[rowBegin][i] = value++;
            }
            ++rowBegin;

            // Traverse the rightmost column
            for (int i = rowBegin; i < rowEnd; ++i) {
                output[i][colEnd - 1] = value++;
            }
            --colEnd;

            // Traverse the bottom row
            if (rowBegin < rowEnd) {
                for (int i = colEnd - 1; i >= colBegin; --i) {
                    output[rowEnd - 1][i] = value++;
                }
                --rowEnd;
            }

            // Traverse the leftmost column
            if (colBegin < colEnd) {
                for (int i = rowEnd - 1; i >= rowBegin; --i) {
                    output[i][colBegin] = value++;
                }
                ++colBegin;
            }
        }

        return output;
    }
};

