class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        int l = 0, r = m-1, u = 0, d = n-1;

        vector<int>ans;
        int k = 0;

        while(k<n*m){

            for(int j=l;j<=r && k<n*m;j++){
                ans.push_back(matrix[u][j]);
                k++;
            }
            if(k>=n*m) break;
            u++;

            for(int i=u;i<=d && k<n*m;i++){
                ans.push_back(matrix[i][r]);
                k++;
            }
            if(k>=n*m) break;
            r--;

            for(int j=r;j>=l && k<n*m;j--){
                ans.push_back(matrix[d][j]);
                k++;
            }
            if(k>=n*m) break;
            d--;

            for(int i=d;i>=u && k<n*m;i--){
                ans.push_back(matrix[i][l]);
                k++;
            }
            if(k>=n*m) break;
            l++;
        }

        // while(ans.size()>n*m) ans.pop_back();

        return ans;
    }
};
