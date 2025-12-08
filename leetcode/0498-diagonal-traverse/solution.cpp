class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        bool flag=false;
        vector<int>ans;

        for(int i=0;i<n;i++){
            
            int k =i;
            int j=0;

            vector<int>temp;
            while(k>=0 && j<m){
                temp.push_back(mat[k][j]);
                k--;
                j++;
            }

            if(flag){
                reverse(temp.begin(),temp.end());
            }
            flag=!flag;


            for(auto ele:temp){
                ans.push_back(ele);
            }
        }

        for(int j=1;j<m;j++){
            
            int k=j;
            int i=n-1;

            vector<int>temp;
            while(k<m && i>=0){
                temp.push_back(mat[i][k]);
                k++;
                i--;
            }

            if(flag){
                reverse(temp.begin(),temp.end());
                for(auto ele:temp){
                    cout<<ele<<" ";
                }
                cout<<"\n";
            }
            flag=!flag;

            for(auto ele:temp){
                ans.push_back(ele);
            }
        }

        return ans;
    }
};
