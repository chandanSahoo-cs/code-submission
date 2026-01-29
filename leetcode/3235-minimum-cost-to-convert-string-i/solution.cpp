#define ll long long

const ll INF = LLONG_MAX;

class Solution {
public:
    ll minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();

        vector<vector<ll>>adj(26,vector<ll>(26,INF));

        for(int i=0;i<n;i++){
            adj[original[i]-'a'][changed[i]-'a'] = min(adj[original[i]-'a'][changed[i]-'a'],(ll)cost[i]);
        }

        for(int i=0;i<26;i++){
            adj[i][i]=0;
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(adj[i][k]==INF || adj[k][j]==INF) continue;
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }

        int m = source.size();
        ll ans = 0;

        for(int i=0;i<m;i++){
            ll c = adj[source[i]-'a'][target[i]-'a'];

            if(c==INF) return -1;
            ans+=c;
        }

        return ans;

    }
};
