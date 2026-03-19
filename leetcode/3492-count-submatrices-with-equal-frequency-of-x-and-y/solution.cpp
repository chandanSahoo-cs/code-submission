class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<pair<int,int>>>vp(n,vector<pair<int,int>>(m));
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x = grid[i][j]=='X';
                int y = grid[i][j]=='Y';

                if(i>0){
                    x+=vp[i-1][j].first;
                    y+=vp[i-1][j].second;
                }

                if(j>0){
                    x+=vp[i][j-1].first;
                    y+=vp[i][j-1].second;
                }

                if(i>0 && j>0){
                    x-=vp[i-1][j-1].first;
                    y-=vp[i-1][j-1].second;
                }

                if(x>0 && x==y) cnt++;
                
                vp[i][j] = {x,y};
            }
        }

        return cnt;
    }
};
