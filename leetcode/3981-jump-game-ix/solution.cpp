class DSU{
    private : 
    vector<int>parent,mx;

    public : 
    DSU(int n, vector<int>nums){
        parent.resize(n),
        mx = nums;

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unite(int u,int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);

        if(ult_u==ult_v) return;

        if(mx[ult_u]>mx[ult_v]){
            parent[ult_v] = ult_u;
        }else{
            parent[ult_u] = ult_v;
        }
    }
};

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        DSU ds(n,nums);

        vector<int>prefMx(n),suffMn(n);

        prefMx[0] = nums[0];
        suffMn[n-1] = nums[n-1];

        for(int i=1;i<n;i++){
            prefMx[i] = max(prefMx[i-1],nums[i]);
        }

        for(int i=n-2;i>=0;i--){
            suffMn[i] = min(suffMn[i+1],nums[i]);
        }

        for(int i=n-2;i>=0;i--){
            if(prefMx[i]>suffMn[i+1]){
                ds.unite(i,i+1);
            }
        }

        vector<int>ans(n);

        for(int i=0;i<n;i++){
            ans[i] = nums[ds.findParent(i)];
        }

        return ans;
    }
};
