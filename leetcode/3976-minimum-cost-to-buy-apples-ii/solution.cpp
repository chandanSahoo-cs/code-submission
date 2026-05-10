#define ll long long
const ll INF = 1e12;

class Solution {
public:
    vector<ll> dijsktra(vector<vector<tuple<int,int,int>>> &adj, int src, bool taxed){
        int n = adj.size();
        
        vector<ll>dist(n,INF);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>pq;

        pq.push({0,src});
        dist[src] = 0;

        while(!pq.empty()){
            auto [cost,u] = pq.top();
            pq.pop();

            if(dist[u]<cost) continue;

            for(auto &[v,c,t]:adj[u]){
                if(dist[v]>(cost+c*1LL*(taxed?t:1))){
                    dist[v] = cost+c*1LL*(taxed?t:1);
                    pq.push({dist[v],v});
                }
            }
        }

        return dist;
    }

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<tuple<int,int,int>>>adj(n);

        for(auto &ele:roads){
            adj[ele[0]].push_back({ele[1],ele[2],ele[3]});
            adj[ele[1]].push_back({ele[0],ele[2],ele[3]});
        }

        vector<int>ans(n);

        for(int i=0;i<n;i++){
            vector<ll>taxed = dijsktra(adj,i,true);
            vector<ll>relief = dijsktra(adj,i,false);

            ll mn = 1e12;
            ans[i] = prices[i];

            for(int j=0;j<n;j++){
                mn = min(mn,prices[j]+taxed[j]+relief[j]);
            }

            ans[i] = (int)min(mn,1LL*ans[i]);
        }

        return ans;
    }
};
