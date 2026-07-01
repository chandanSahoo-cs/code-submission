class Solution {
public:
    vector<vector<int>> generate(vector<vector<int>>&grid){
        int n = grid.size();

        queue<pair<int,int>>q;
        vector<vector<int>>temp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j});
                    temp[i][j]=0;
                }
            }
        }

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        int level = 1;

        while(!q.empty()){

            int sz = q.size();

            while(sz--){
                auto [i,j] = q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int r = i+dr[k];
                    int c = j+dc[k];

                    if(r<0 || r>=n || c<0 || c>=n || temp[r][c]!=-1) continue;
                    temp[r][c] = level;
                    q.push({r,c});
                }
            }

            level++;
        }

        return temp;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>temp = generate(grid);

        priority_queue<tuple<int,int,int>>pq;
        vector<vector<int>>mark(n,vector<int>(n,INT_MIN));

        pq.push({temp[0][0],0,0});
        mark[0][0]=temp[0][0];

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        while(!pq.empty()){
            auto [dist,i,j] = pq.top();
            pq.pop();

            if(mark[i][j]>dist) continue;

            for(int k=0;k<4;k++){
                int r = i+dr[k];
                int c = j+dc[k];

                if(r<0 || r>=n || c<0 || c>=n || mark[r][c]>=min(temp[r][c],dist)) continue;
                
                mark[r][c] = min(temp[r][c],dist);
                pq.push({mark[r][c],r,c});
            }
        }

        return mark[n-1][n-1];
    }
};
