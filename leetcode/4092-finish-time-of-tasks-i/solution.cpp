#define ll long long
class Solution {
public:

    ll dfs(int n,vector<vector<int>>&adj,vector<int>&baseTime,int u){

        if(adj[u].size()==0) return baseTime[u];

        ll latest = 0, earliest = LLONG_MAX;

        for(auto v:adj[u]){
            ll time = dfs(n,adj,baseTime,v);
            latest = max(latest,time);
            earliest = min(earliest,time);
        }

        ll ownDuration = (latest-earliest)+baseTime[u];

        return latest+ownDuration;
    }
    
    ll finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);

        for(auto &ele:edges){
            adj[ele[0]].push_back(ele[1]);
        }

        return dfs(n,adj,baseTime,0);
    }
};
