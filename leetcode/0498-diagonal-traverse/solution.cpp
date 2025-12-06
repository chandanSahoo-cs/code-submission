class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m=mat[0].size();
        vector<int>ans;
        bool flag=false;

        for(int i=0;i<n;i++){

            int tempi=i;
            int tempj=0;

            vector<int>temp;

            while(tempi>=0 && tempj<m){
                temp.push_back(mat[tempi][tempj]);
                tempi--;
                tempj++;
            }

            if(flag){
                for(int k=temp.size()-1;k>=0;k--){
                    ans.push_back(temp[k]);
                }
            }else{
                for(auto ele:temp){
                    ans.push_back(ele);
                }
            }

            flag=!flag;
        }

        for(int j=1;j<m;j++){
            int tempi=n-1;
            int tempj=j;

            vector<int>temp;

            while(tempi>=0 && tempj<m){
                temp.push_back(mat[tempi][tempj]);
                tempi--;
                tempj++;
            }

            if(flag){
                for(int k=temp.size()-1;k>=0;k--){
                    ans.push_back(temp[k]);
                }
            }else{
                for(auto ele:temp){
                    ans.push_back(ele);
                }
            }

            flag=!flag;
        }

        return ans;
    }
};
