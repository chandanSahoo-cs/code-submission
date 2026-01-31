class DSU{
    vector<int>sz,parent;
    int mx;
    public:
    DSU(int n){
        sz.resize(n,1);
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        mx=1;
    }

    int findParent(int u){
        if(parent[u]==u) return u;

        return parent[u]=findParent(parent[u]);
    }

    void unionBySz(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);

        if(ult_u==ult_v) return;

        if(sz[ult_u]>sz[ult_v]){
            parent[ult_v]=ult_u;
            sz[ult_u]+=sz[ult_v];
            mx = max(mx,sz[ult_u]);
        }else{
            parent[ult_u]=ult_v;
            sz[ult_v]+=sz[ult_u];
            mx = max(mx,sz[ult_v]);
        }
    }

    int indSz(int u){
        int ult_u = findParent(u);

        return sz[ult_u]; 
    }

    int mxSz(){
        return mx;
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DSU ds(n*n);

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;

                int ind = i*n+j;

                for(int k=0;k<4;k++){
                    int r = i+dr[k];
                    int c = j+dc[k];

                    int nind = r*n+c;

                    if(r<0 || r>=n || c<0 || c>=n || grid[r][c]==0) continue;

                    ds.unionBySz(ind,nind);
                }
            }
        }

        int mx = ds.mxSz();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++ ){
                if(grid[i][j]==1) continue;

                int temp = 0;

                unordered_set<int>st;

                for(int k=0;k<4;k++){
                    int r = i+dr[k];
                    int c = j+dc[k];

                    int nind = r*n+c;

                    if(r<0 || r>=n || c<0 || c>=n || grid[r][c]==0) continue;

                    int p = ds.findParent(nind);

                    if(!st.count(p)){
                        st.insert(p);
                        temp+=ds.indSz(nind);
                    }
                }

                mx = max(mx,temp+1);
            }
        }

        return mx;
    }
};
