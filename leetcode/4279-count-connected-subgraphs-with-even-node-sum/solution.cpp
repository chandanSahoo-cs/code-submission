class DSU{
    private : 
    vector<int>sz,parent;
    int components;

    public :
    DSU(int n){
        sz.resize(n),parent.resize(n);
        components = n;
        
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
        components--;

        if(sz[ult_u]>sz[ult_v]){
            parent[ult_v] = ult_u;
            sz[ult_u]+=sz[ult_v];
        }else{
            parent[ult_u] = ult_v;
            sz[ult_v]+=sz[ult_u];
        }

        return;
    }

    int totComp(){
        return components;
    }
};

class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        map<pair<int,int>,bool>mp;

        for(auto &ele:edges){
            mp[{ele[0],ele[1]}]=true;
            mp[{ele[1],ele[0]}]=true;
        }

        int cnt = 0;

        for(int i=1;i<(1<<n);i++){

            vector<int>nodes;

            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    nodes.push_back(j);
                }
            }

            int m = nodes.size();
            DSU ds(m);

            for(int i=0;i<m;i++){
                for(int j=i+1;j<m;j++){
                    int u = nodes[i];
                    int v = nodes[j];

                    if(mp.count({u,v})){
                        ds.unite(i,j);
                    }
                }
            }
            
            if(ds.totComp()==1){
                int sum = 0;
                for(auto ele:nodes){
                    sum+=nums[ele];
                }

                if(!(sum&1)) cnt++;
            }else continue;
        }

        return cnt;
    }
};
