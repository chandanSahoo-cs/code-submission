class TreeAncestor {
    vector<vector<int>>mat;
    int MX = 17;
public:
    // build matrix
    void build(vector<int>&parent){
        int n = parent.size();

        for(int i=0;i<n;i++){
            mat[0][i] = parent[i];
        }

        for(int i=1;i<MX;i++){
            for(int j=0;j<n;j++){
                if(mat[i-1][j]!=-1) mat[i][j] = mat[i-1][mat[i-1][j]];
                else mat[i][j] = -1;
            }
        }

        return ;
    }

    int query(int node, int k){
        int i = 0;
        while(k && node!=-1){
            if(k&1){
                node = mat[i][node];
            }
            k>>=1;
            i++;
        }

        return node;
    }

    TreeAncestor(int n, vector<int>& parent) {
        mat.resize(MX,vector<int>(n,-1));
        build(parent);
    }
    
    int getKthAncestor(int node, int k) {
        return query(node,k);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
