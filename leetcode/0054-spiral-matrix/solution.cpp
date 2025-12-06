class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        int m = matrix[0].size()-1;


        int i=0,j=0;
        vector<int>ans;

        while(i<=n && j<=m){
            for(int k=j;k<=m;k++){
                ans.push_back(matrix[i][k]);
            }
            i++;
            cout<<i<<","<<n<<","<<j<<","<<m<<"\n";
            if(i>n || j>m) break;

            for(int k=i;k<=n;k++){
                ans.push_back(matrix[k][m]);
            }
            m--;
            cout<<i<<","<<n<<","<<j<<","<<m<<"\n";
            if(i>n || j>m) break;

            for(int k=m;k>=j;k--){
                ans.push_back(matrix[n][k]);
            }
            n--;
            cout<<i<<","<<n<<","<<j<<","<<m<<"\n";
            if(i>n || j>m) break;

            for(int k=n;k>=i;k--){
                ans.push_back(matrix[k][j]);
            }
            j++;
            cout<<i<<","<<n<<","<<j<<","<<m<<"\n";
            if(i>n || j>m) break;
        }

        return ans;
    }
};
