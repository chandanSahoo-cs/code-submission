class DSU{
    vector<int>sz,parent;

    public:
    DSU(int n){
        sz.resize(n,1);
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
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
        }else{
            parent[ult_u]=ult_v;
            sz[ult_v]+=sz[ult_u];
        }

        return;
    }

    int totSets(){
        int cnt=0;

        for(int i=0;i<parent.size();i++){
            if(i==parent[i]) cnt++;
        }

        return cnt;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int extra=0;

        for(auto ele:connections){
            int u = ele[0], v = ele[1];
            if(ds.findParent(u)==ds.findParent(v)){
                extra++;
            }else{
                ds.unionBySz(u,v);
            }
        }

        int required = ds.totSets()-1;

        if(extra<required) return -1;
        return required;
    }
};
