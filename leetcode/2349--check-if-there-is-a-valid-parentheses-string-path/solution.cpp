class Solution {
public:
    unordered_set<int>dp[105][105];
    bool vis[105][105];

    unordered_set<int> &rec(vector<vector<char>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();

        if(i==n-1 && j==m-1){
            if(grid[i][j]==')') return dp[i][j]={-1};
            return dp[i][j]={100000};
        }

        if(i==n || j==m) return dp[i][j]={100000};

        if(vis[i][j]) return dp[i][j];

        unordered_set<int>&down=rec(grid,i+1,j);
        unordered_set<int>&right=rec(grid,i,j+1);

        unordered_set<int>curr;
        int val = grid[i][j]=='('?1:-1;

        for(auto ele:down){
            if(ele+val<=0) curr.insert(ele+val);
        }

        for(auto ele:right){
            if(ele+val<=0) curr.insert(ele+val);
        }

        vis[i][j]=true;
        return dp[i][j]=curr;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        memset(vis,0,sizeof(vis));
        
        unordered_set<int>st=rec(grid,0,0);

        return st.count(0);
    }
};
