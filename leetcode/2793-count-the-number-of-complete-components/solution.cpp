class DSU{
    private:
    vector<int>parent,sz,edges;

    public:
    DSU(int n){
        parent.resize(n);
        sz.resize(n);
        edges.resize(n);

        for(int i=0;i<n;i++){
            parent[i] = i;
            sz[i] = 1;
            edges[i] = 0;
        }

    }

    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unite(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);

        if(ult_u==ult_v){
            edges[ult_u]++;
            return;
        }

        if(sz[ult_u]>sz[ult_v]){
            parent[ult_v] = ult_u;
            sz[ult_u]+=sz[ult_v];
            edges[ult_u]+=edges[ult_v]+1;
        }else{
            parent[ult_u] = ult_v;
            sz[ult_v]+=sz[ult_u];
            edges[ult_v]+=edges[ult_u]+1;
        }

        return;
    }

    pair<int,int>give(int u){
        return {sz[u],edges[u]};
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>mark(n);

        DSU ds(n);

        for(auto &ele:edges){
            int u = ele[0], v = ele[1];
            ds.unite(u,v);
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            int par = ds.findParent(i);

            if(mark[par]) continue;
            mark[par]=1;

            auto [sz,edges] = ds.give(par);

            if((sz*(sz-1))/2==edges) ans++;
        }

        return ans;
    }
};
