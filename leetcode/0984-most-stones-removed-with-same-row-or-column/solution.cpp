const int sz = 1e4+1;

class DisjointSet{
    vector<int>sze,parent;
    public:
    DisjointSet(){
        sze.resize(2*sz);
        parent.resize(2*sz);

        for(int i=0;i<2*sz;i++){
            parent[i]=i;
        }
    }

    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void Union(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);

        if(ult_u==ult_v) return;

        if(sze[ult_u]>sze[ult_v]){
            parent[ult_v]=ult_u;
            sze[ult_u]+=sze[ult_v];
        }else{
            parent[ult_u]=ult_v;
            sze[ult_v]+=sze[ult_u];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        DisjointSet ds;

        for(auto ele:stones){
            int u = ele[0];
            int v = ele[1]+sz;

            int ult_u = ds.findParent(u);
            int ult_v = ds.findParent(v);

            if(ult_u==ult_v){
                continue;
            }

            ds.Union(ult_u,ult_v);
        }

        set<int>st;

        for(auto ele:stones){
            int u = ele[0];
            int v = ele[1]+sz;

            int ult_u = ds.findParent(u);
            // int ult_v = ds.findParent(v);

            st.insert(ult_u);
            // st.insert(ult_v);
        }

        return n-st.size();

    }
};
