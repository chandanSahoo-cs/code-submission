class DSU{
    private:
    vector<int>parent,sz;

    public: 
    DSU(int n){
        parent.resize(n);
        sz.resize(n);

        for(int i=0;i<n;i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int findParent(int u){
        if(u==parent[u]) return u;
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
            sz[ult_v]+= ult_u;
        }

        return;
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        DSU ds(n);

        for(int i=n-1;i>=1;i--){
            if(nums[i]-nums[i-1]<=maxDiff){
                ds.unite(i,i-1);
            }
        }

        vector<bool>ans;

        for(auto &ele:queries){
            int u = ele[0], v = ele[1];
            if(ds.findParent(u)==ds.findParent(v)){
                ans.push_back(true);
            }else ans.push_back(false);
        }

        return ans;
    }
};
