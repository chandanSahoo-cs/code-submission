const int INF = 1e9+7;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>>dist(n,vector<int>(n,INF));

        queue<tuple<int,int,int>>q;
        
        if(grid[0][0]==1){
            return -1;
        }
        q.push({1,0,0});
        dist[0][0]=1;

        while(!q.empty()){
            auto [cost,i,j] = q.front();
            q.pop();

            for(int r=-1;r<=1;r++){
                for(int c=-1;c<=1;c++){
                    int row = i+r;
                    int col = j+c;

                    if(row<0 || row>=n || col<0 || col>=n || grid[row][col]==1) continue;

                    if(dist[row][col]>1+cost){
                        dist[row][col] = 1+cost;
                        q.push({1+cost,row,col});
                    }
                }
            }
        }

        return dist[n-1][n-1]==INF?-1:dist[n-1][n-1];
    }
};
