class DSU{
    private: 
    vector<int>parent,sz;
    int comp;
    public:

    DSU(int n){
        parent.resize(n);
        sz.resize(n);
        comp=n;

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
        comp--;

        if(sz[ult_u]>sz[ult_v]){
            parent[ult_v] = ult_u;
            sz[ult_u]+=sz[ult_v];
        }else{
            parent[ult_u] = ult_v;
            sz[ult_v]+=sz[ult_u];
        }

        return;
    }

    int components(){
        return comp;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        
        unordered_map<int,int>pFact;
        DSU ds(n);

        for(int i=0;i<n;i++){
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    if(j!=1){
                        if(pFact.count(j)){
                            ds.unite(pFact[j],i);
                            if(ds.components()==1) return true;
                        }
                        pFact[j]=i;
                    }
                    int k = nums[i]/j;
                    if(k!=j){
                        if(pFact.count(k)){
                            ds.unite(pFact[k],i);
                            if(ds.components()==1) return true;
                        }
                        pFact[k]=i;
                    }
                }
            }
        }

        return false;
    }
};
