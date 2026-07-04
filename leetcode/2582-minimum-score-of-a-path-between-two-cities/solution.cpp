class DSU{
    private:
    vector<int>parent,sz;

    public:
    DSU(int n){
        parent.resize(n+1);
        sz.resize(n+1);

        for(int i=1;i<=n;i++){
            parent[i]=i;
            sz[i]=1;
        }
    }

    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unite(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);

        if(ult_u==ult_v) return ;

        if(sz[ult_u]>sz[ult_v]){
            parent[ult_v] = ult_u;
            sz[ult_u]+=sz[ult_v];
        }else{
            parent[ult_u] = ult_v;
            sz[ult_v]+=sz[ult_u];
        }

        return;
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU ds(n);

        for(auto &ele:roads){
            ds.unite(ele[0],ele[1]);
        }

        int mn = INT_MAX;

        for(auto &ele:roads){
            if(ds.findParent(ele[0])==ds.findParent(1)){
                mn = min(mn,ele[2]);
            }
        }      

        return mn;
    }
};
