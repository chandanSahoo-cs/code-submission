class DSU{
    private:
    vector<int>parent,sz;
    vector<vector<int>>aval;
    vector<int>ptr;

    public:
    DSU(int n){
        parent.resize(n);
        sz.resize(n);
        aval.resize(n);
        ptr.resize(n);
        
        for(int i=0;i<n;i++){
            parent[i] = i;
            sz[i] = 1;
            aval[i].push_back(i);
            ptr[i]=0;
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

        if(sz[ult_u]>=sz[ult_v]){
            sz[ult_u]+=sz[ult_v];
            parent[ult_v] = ult_u;
            aval[ult_u].push_back(v);
        }else{
            sz[ult_v]+=sz[ult_u];
            parent[ult_u]=ult_v;
            aval[ult_v].push_back(u);
        }

        return;
    }

    int look(int u){
        int ult_u = findParent(u);

        return aval[ult_u][ptr[ult_u]++];
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int>a = nums;
        sort(a.begin(),a.end());

        DSU ds(n);
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]<=limit) ds.unite(i-1,i);
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            int idx = lower_bound(a.begin(),a.end(),nums[i])-a.begin();
            ans.push_back(a[ds.look(idx)]);
        }

        return ans;
    }
};
