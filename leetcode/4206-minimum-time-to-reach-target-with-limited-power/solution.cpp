#define ll long long

class Solution {
public:
    vector<ll> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int src, int trg) {
        vector<vector<pair<ll,ll>>>adj(n);

        for(auto &ele:edges){
            int u = ele[0];
            int v = ele[1];
            int t = ele[2];

            adj[u].push_back({v,t});
        }

        vector<vector<ll>>mark(n,vector<ll>(power+1,LLONG_MAX));

        priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<>>pq;
        /*
        first: time
        second: power
        third: vertex
        */
        pq.push({0,power,src});
        mark[src][power]=0;

        ll mnTime = LLONG_MAX;
        ll mxPower = LLONG_MIN;

        while(!pq.empty()){
            auto [t,p,u] = pq.top();
            pq.pop();

            if(u==trg){
               if(mnTime>t){
                mnTime = t;
                mxPower = p;
               }else if(mnTime==t){
                mxPower = max(mxPower,p);
               }

               continue;
            }

            if(mark[u][p]<t) continue;

            for(auto &[v,time]:adj[u]){
                if(p-cost[u]>=0){
                    if(time+t<mark[v][p-cost[u]]){
                        mark[v][p-cost[u]] = t+time;
                        pq.push({t+time,p-cost[u],v});
                    }
                }
            }
        }

        return {mnTime!=LLONG_MAX?mnTime:-1, mxPower!=LLONG_MIN?mxPower:-1};
    }
};
