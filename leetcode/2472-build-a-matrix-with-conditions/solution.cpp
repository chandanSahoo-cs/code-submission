class Solution {
public:

    bool kahn(int k, vector<vector<int>>& cond, vector<int>& seq){
        vector<vector<int>>adj(k+1);
        vector<int>in(k+1);

        for(auto &ele:cond){
            adj[ele[0]].push_back(ele[1]);
            in[ele[1]]++;
        }

        queue<int>q;

        for(int i=1;i<=k;i++){
            if(in[i]==0) q.push(i);
        }

        int comp = k;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            k--;
            seq.push_back(u);

            for(auto v:adj[u]){
                in[v]--;
                if(in[v]==0){
                    q.push(v);
                }
            }
        }

        return k==0;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int>row,col;

        if(!kahn(k,rowConditions,row)) return {};
        if(!kahn(k,colConditions,col)) return {};

        vector<pair<int,int>>ind(k+1);

        for(int i=0;i<k;i++){
            ind[row[i]].first = i;
            ind[col[i]].second = i;
        }

        vector<vector<int>>ans(k,vector<int>(k));

        for(int i=1;i<=k;i++){
            ans[ind[i].first][ind[i].second]=i;
        }

        return ans;
    }
};
