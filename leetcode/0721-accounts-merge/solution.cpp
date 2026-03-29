class DSU{
    private : 
    vector<int>parent,sz;

    public : 
    DSU(int n){
        parent.resize(n);
        sz.resize(n);

        for(int i=0;i<n;i++){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n = a.size();

        map<string,int>strPr;

        DSU ds(n);

        for(int i=0;i<n;i++){
            for(int j=1;j<a[i].size();j++){
                if(strPr.find(a[i][j])!=strPr.end()){
                    ds.unite(strPr[a[i][j]],i);
                }else{
                    strPr[a[i][j]]=i;
                }
            }
        }

        vector<vector<string>>store(n);

        for(int i=0;i<n;i++){
            store[i].push_back(a[i][0]);
        }

        for(auto [key,value]:strPr){
            int ind = ds.findParent(value);
            store[ind].push_back(key);
        }

        vector<vector<string>>ans;

        for(auto ele:store){
            if(ele.size()>1) ans.push_back(ele);
        }

        return ans;
    }
};
