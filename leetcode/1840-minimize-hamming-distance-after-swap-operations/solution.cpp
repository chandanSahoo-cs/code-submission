class DSU{
    private : 
    vector<int>sz,parent;

    public : 
    DSU(int n){
        sz.resize(n);
        parent.resize(n);

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

        if(ult_u==ult_v) return;

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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& as) {
        int n = source.size();

        DSU ds(n);

        for(auto &ele:as){
            ds.unite(ele[0],ele[1]);
        }

        unordered_map<int,unordered_map<int,int>>mp;

        for(int i=0;i<n;i++){
            int par = ds.findParent(i);
            mp[par][source[i]]++;
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            int par = ds.findParent(i);

            if(mp[par][target[i]]>0){
                mp[par][target[i]]--;
            }else{
                cnt++;
            }
        }

        return cnt;

    }
};
