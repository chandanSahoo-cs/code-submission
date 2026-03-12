class DSU{
    vector<int>sz,parent;
    int comp;

    public:
    DSU(int n){
        sz.resize(n);
        parent.resize(n);
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

        if(ult_u==ult_v) return ;
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

    int totalComp(){
        return comp;
    }
};

class Solution {
public:

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        
        DSU ds(n);

        sort(edges.begin(),edges.end(),[&](vector<int>&e1,vector<int>&e2){
            if(e1[3]==0 && e2[3]==0){
                return e1[2]>e2[2];
            }else return e1[3]>e2[3];
        });

        int i=0;

        int mn = INT_MAX;

        vector<int>store;

        while(i<edges.size()){
            int u = edges[i][0];
            int v = edges[i][1];
            int s = edges[i][2];
            int m = edges[i][3];

            int ult_u = ds.findParent(u);
            int ult_v = ds.findParent(v);

            if(ult_u==ult_v){
                if(m==1) return -1;
            }else{
                ds.unite(ult_u,ult_v);
                if(m!=1) store.push_back(s);
                else{
                    mn = min(mn,s);
                }
            }

            i++;
        }

        if(ds.totalComp()>1) return -1;

        for(int j = store.size()-1;j>=0 && k>=0;j--){
            int ele = store[j];
            if(k>0){
                mn = min(ele*2,mn);
                k--;
            }else{
                mn = min(ele,mn);
            }
        }

        return mn;
    }
};

