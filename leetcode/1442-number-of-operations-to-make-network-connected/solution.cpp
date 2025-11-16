class DisjointSet {
    vector<int>sze,parent;
    public:
    DisjointSet(int n){
        sze.resize(n);
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

        if(ult_u==ult_v) return ;

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int cnt=0;

        for(auto ele:connections){
            int ult_u = ds.findParent(ele[0]);
            int ult_v = ds.findParent(ele[1]);

            if(ult_u==ult_v){
                cnt++;
                continue;
            }

            ds.Union(ele[0],ele[1]);
        }

        int totUsed = connections.size()-cnt;

        if(n-1-totUsed>cnt) return -1;
        else return n-1-totUsed;
    }
};
