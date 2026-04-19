class Solution {
public:
    void cSort(vector<vector<int>> &a, queue<tuple<int,int,int>> &q, vector<vector<int>> &grid){
        sort(a.begin(),a.end(),[&](vector<int>&p1,vector<int>&p2){
            return p1[2]>p2[2];
        });
        
        for(auto &ele:a){
            int r = ele[0], c = ele[1], color = ele[2];
            q.push({r,c,color});
            grid[r][c] = color;
        }

        return;
    }
    
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>grid(n,vector<int>(m));
        queue<tuple<int,int,int>>q;
        
        cSort(sources,q,grid);

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};
        
        while(!q.empty()){
            int sz = q.size();

            vector<vector<int>>a;
            for(int i=0;i<sz;i++){
                auto [r,c,color] = q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int tr = r+dr[k];
                    int tc = c+dc[k];

                    if(tr<0 || tr>=n || tc<0 || tc>=m || grid[tr][tc]) continue;
                    grid[tr][tc] = color;
                    a.push_back({tr,tc,color});
                }
            }
            cSort(a,q,grid);
        }

        return grid;
    }
};
