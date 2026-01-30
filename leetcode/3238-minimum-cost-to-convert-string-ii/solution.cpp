#define ll long long
const ll INF = 1e12+7;

class Solution {
public:
    ll minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {

        ll n = original.size();

        unordered_map<string,ll>mp;
        unordered_set<ll>st;
        ll idx = 0;

        for(int i=0;i<n;i++){
            if(mp.find(original[i])==mp.end()) mp[original[i]]=idx++;
            if(mp.find(changed[i])==mp.end()) mp[changed[i]]=idx++;
            st.insert(changed[i].size());
        }

        vector<vector<ll>>adj(idx,vector<ll>(idx,INF));
        vector<ll>lens(st.begin(),st.end());


        for(int i=0;i<n;i++){
            adj[mp[original[i]]][mp[changed[i]]]=min(adj[mp[original[i]]][mp[changed[i]]],(ll)cost[i]);
        }

        for(int i=0;i<idx;i++){
            adj[i][i]=0;
        }

        for(int k=0;k<idx;k++){
            for(int i=0;i<idx;i++){
                for(int j=0;j<idx;j++){
                    if(adj[i][k]==INF || adj[k][j]==INF) continue;
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }

        ll m = source.size();

        vector<ll>dp(m+1,INF);
        dp[m]=0;

        for(int i=m-1;i>=0;i--){

            if(source[i]==target[i]){
                dp[i] = min(dp[i],dp[i+1]);
            }


            for(auto l:lens){

                if(i+l>m) continue;

                if(st.count(l)){
                    string s = source.substr(i,l);
                    string t = target.substr(i,l);
                    
                    ll val = dp[i+l];

                    if((mp.find(s)!=mp.end() && mp.find(t)!=mp.end())){
                        if(val!=INF){
                            dp[i] = min(dp[i],adj[mp[s]][mp[t]]+dp[i+l]);
                        }
                    }
                }
            }
        }

        return dp[0]==INF?-1:dp[0];
    }
};
