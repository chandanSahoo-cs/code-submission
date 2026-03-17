class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<pair<int,int>>a;
        int ans = 0;

        for(int i=0;i<n;i++){
            vector<int>mark(m,0);
            vector<pair<int,int>>na;

            for(auto &[height,col]:a){
                if(matrix[i][col]==1){
                    na.push_back({height+1,col});
                    mark[col]=1;
                }
            }

            for(int j=0;j<m;j++){
                if(mark[j]) continue;
                if(matrix[i][j]==1){
                    na.push_back({1,j});
                }
            }

            a = na;

            for(int j=0;j<na.size();j++){
                ans = max(ans,na[j].first*(j+1));
            }
        }

        return ans;
    }
};
