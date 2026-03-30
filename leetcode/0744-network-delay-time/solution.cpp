class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dist(n+1,INT_MAX);

        for(auto &ele:times){
            adj[ele[0]].push_back({ele[1],ele[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()){
            auto [w,u]= pq.top();
            pq.pop();

            if(dist[u]<w) continue;

            for(auto &[v,weigh]:adj[u]){
                if(weigh+w<dist[v]){
                    dist[v] = weigh+w;
                    pq.push({dist[v],v});
                }
            }
        }

        int mx = 0;

        for(int i=1;i<=n;i++){
            mx = max(dist[i],mx);
            if(dist[i]==INT_MAX) return -1;
        }

        return mx;
    }
};
