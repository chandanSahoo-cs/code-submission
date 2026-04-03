class DSU{
    
    vector<int>parent,sz;

    public : 
    DSU(int n){
        parent.resize(n);
        sz.resize(n);

        for(int i=0;i<n;i++){
            parent[i] = i;
            sz[i] = 1;
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

    int kruskal(int n, vector<vector<int>>&edges, vector<int>&ind, int take, int skip){

        int m = ind.size();

        DSU ds(n);

        int sum = 0;

        if(take!=-1){
            int u = edges[take][0], v = edges[take][1], w = edges[take][2];

            sum+=w;

            ds.unite(u,v);
        }

        for(int i=0;i<m;i++){
            if(ind[i]==skip || ind[i]==take) continue;
            int u = edges[ind[i]][0], v = edges[ind[i]][1], w = edges[ind[i]][2];

            int ult_u = ds.findParent(u), ult_v = ds.findParent(v);

            if(ult_u==ult_v) continue;

            sum+=w;

            ds.unite(u,v);
        }

        return sum;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int>ind(m);
        iota(ind.begin(),ind.end(),0);

        sort(ind.begin(),ind.end(),[&](int i, int j){
            return edges[i][2]<edges[j][2];
        });

        int mstSum = kruskal(n,edges,ind,-1,-1);

        vector<int>crit,pseudo;


        for(int i=0;i<m;i++){
            int p = kruskal(n,edges,ind,ind[i],-1);
            int np = kruskal(n,edges,ind,-1,ind[i]);

            if(p==mstSum){
                if(np==mstSum) pseudo.push_back(ind[i]);
                else crit.push_back(ind[i]);
            }
        }

        return {crit,pseudo};
    }
};
