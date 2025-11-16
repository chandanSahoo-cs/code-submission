class DisjointSet{
    vector<int>sz,parent;

    public:
    DisjointSet(int n){
        sz.resize(n);
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u]=findParent(parent[u]);
    }

    void Union(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);

        if(ult_u==ult_v) return;

        if(sz[ult_u]>sz[ult_v]){
            parent[ult_v]=ult_u;
            sz[ult_u]+=sz[ult_v];
        }else{
            parent[ult_u]=ult_v;
            sz[ult_v]+=ult_u;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n = a.size();
        
        DisjointSet ds(n);

        map<string, int>mp;

        for(int i=0;i<n;i++){
            int m = a[i].size();
            for(int j=1;j<m;j++){
                if(mp.find(a[i][j])!=mp.end()){
                    ds.Union(mp[a[i][j]],i);
                }else{
                    mp[a[i][j]]=i;
                }
            }
        }
        vector<vector<string>>store(n);

        for(int i=0;i<n;i++){
            store[i].push_back(a[i][0]);
        }

        for(auto [key,value]:mp){
            int ult = ds.findParent(value);
            store[ult].push_back(key);
        }

        vector<vector<string>>ans;

        for(int i=0;i<n;i++){
            if(store[i].size()>1) ans.push_back(store[i]);
        }

        return ans;
    }
};
