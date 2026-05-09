class Solution {
public:
    void get(vector<vector<int>>&grid, vector<int>&store, int l, int r, int t, int d){
        for(int i=l;i<r;i++){
            store.push_back(grid[t][i]);
        }

        // right, top->down
        for(int i=t;i<d;i++){
            store.push_back(grid[i][r]);
        }

        // bottom , right->left
        for(int i=r;i>l;i--){
            store.push_back(grid[d][i]);
        }

        // left, bottom->top
        for(int i=d;i>t;i--){
            store.push_back(grid[i][l]);
        }
    }

    void fill(vector<vector<int>>&ans, vector<int>&store, int l, int r, int t, int d){
        int itr = 0;
        for(int i=l;i<r;i++){
            ans[t][i] = store[itr++];
        }

        // right, top->down
        for(int i=t;i<d;i++){
            ans[i][r] = store[itr++];
        }

        // bottom , right->left
        for(int i=r;i>l;i--){
            ans[d][i] = store[itr++];
        }

        // left, bottom->top
        for(int i=d;i>t;i--){
            ans[i][l] = store[itr++];
        }
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        int l = 0, r = m-1, t = 0, d = n-1;

        vector<vector<int>>ans(n,vector<int>(m));

        while(l<r && t<d){
            vector<int>store;
            get(grid,store,l,r,t,d);

            int sz = store.size();
            int rot = k%sz;

            rotate(store.begin(),store.begin()+rot,store.end());
            fill(ans,store,l,r,t,d);

            l++,r--;
            t++,d--;
        }

        return ans;
    }
};

