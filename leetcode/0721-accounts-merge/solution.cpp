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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DSU ds(n);

        map<string,int>mp;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    ds.unionBySz(mp[accounts[i][j]],i);
                }else{
                    mp[accounts[i][j]]=i;
                }
            }
        }

        vector<vector<string>>store(n);

        for(int i=0;i<n;i++){
            store[i].push_back(accounts[i][0]);
        }

        for(auto [key,value]:mp){
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
