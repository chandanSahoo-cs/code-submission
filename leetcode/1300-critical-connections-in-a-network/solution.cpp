class Solution {
    const int INF = 1e6;
public:

    int rec(vector<vector<int>>&adj,vector<int>&time,vector<int>&lTime,vector<vector<int>>&ans, int cnt,int node, int parent){
        time[node]=cnt;
        lTime[node]=cnt;
        cnt++;
        for(auto ele:adj[node]){
            if(ele!=parent && time[ele]==-1){
                int t = rec(adj,time,lTime,ans,cnt,ele,node);
                if(t>lTime[node]){
                    ans.push_back({ele,node});
                }
            }
        }

        int mnTime = INF;

        for(auto ele:adj[node]){
            if(ele!=parent){
                mnTime = min(mnTime,lTime[ele]);
            }
        }

        return lTime[node]=mnTime;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);

        for(auto ele:connections){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }

        vector<vector<int>>ans;
        vector<int>time(n,-1);
        vector<int>lTime(n,-1);

        for(int i=0;i<n;i++){
            if(time[i]!=-1) continue;
            rec(adj,time,lTime,ans,0,i,-1);
        }

        return ans;
    }
};
