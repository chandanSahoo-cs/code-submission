const int mx = 1e4+1;
class DSU{

    vector<int>sz,parent;
    public:
    DSU(){
        sz.resize(2*mx,1);
        parent.resize(2*mx);

        for(int i=0;i<2*mx;i++){
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        DSU ds;

        for(auto ele:stones){
            int u = ele[0];
            int v = ele[1]+mx;

            ds.unionBySz(u,v);
        }

        unordered_set<int>st;

        for(auto ele:stones){
            int u = ele[0];
            int v = ele[1]+mx;

            if(ds.findParent(u)==u){
                st.insert(u);
            }

            if(ds.findParent(v)==v){
                st.insert(v);
            }
        }

        return n-st.size();
    }
};
