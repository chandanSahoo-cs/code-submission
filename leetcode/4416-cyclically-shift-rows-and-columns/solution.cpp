class Solution {
public:
    
    void shift(vector<int>&a, int k){
        int n = a.size();
        k = n-(k%n);

        reverse(a.begin(),a.end());
        reverse(a.begin(),a.begin()+k);
        reverse(a.begin()+k,a.end());

        return;
    }

    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        for(int i=0;i<n;i++){
            vector<int>a;
            for(int j=0;j<n;j++){
                a.push_back(grid[i][j]);
            }
            shift(a,rowShift[i]);
            
            for(int j=0;j<n;j++){
                grid[i][j] = a[j];
            }
        }

        for(int j=0;j<n;j++){
            vector<int>a;
            for(int i=0;i<n;i++){
                a.push_back(grid[i][j]);
            }
            shift(a,colShift[j]);
            
            for(int i=0;i<n;i++){
                grid[i][j] = a[i];
            }
        }

        return grid;
    }
};
