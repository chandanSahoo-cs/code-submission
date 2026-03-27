class Solution {
public:
    void bfs(vector<vector<int>>&a, vector<vector<int>>&vis, queue<pair<int,int>>&q){
        int n = a.size(), m = a[0].size();

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        while(!q.empty()){
            int sz = q.size();

            for(int i=0;i<sz;i++){
                auto [r,c] = q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int tr = r+dr[k];
                    int tc = c+dc[k];

                    if(tr<0 || tr>=n || tc<0 || tc>=m || a[tr][tc]<a[r][c] || vis[tr][tc]) continue;
                    vis[tr][tc]=1;
                    q.push({tr,tc});
                }
            }
        }

        return ;
    }

    vector<vector<int>> pacific(vector<vector<int>>& a){
        int n = a.size(), m = a[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            vis[i][0]=1;
            q.push({i,0});
        }

        for(int j=1;j<m;j++){
            vis[0][j]=1;
            q.push({0,j});
        }

        bfs(a,vis,q);

        return vis;
    }

    vector<vector<int>> atlantic(vector<vector<int>>& a){
        int n = a.size(), m = a[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            vis[i][m-1]=1;
            q.push({i,m-1});
        }

        for(int j=0;j<m-1;j++){
            vis[n-1][j]=1;
            q.push({n-1,j});
        }

        bfs(a,vis,q);

        return vis;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();

        vector<vector<int>>vis1 = pacific(a);
        vector<vector<int>>vis2 = atlantic(a);

        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j] && vis2[i][j]) ans.push_back({i,j});
            }
        }

        return ans;
    }
};
