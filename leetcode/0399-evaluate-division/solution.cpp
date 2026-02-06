class Solution {
public:

    double dfs(unordered_map<string,vector<pair<double,string>>> &adj,unordered_set<string>&st, string curr, string tr){
        if(curr==tr) return 1.0;
        if(st.count(curr)) return -1;
        st.insert(curr);

        for(auto &[val,str]:adj[curr]){
            double hold = dfs(adj,st,str,tr);
            if(hold!=-1){
                return val*hold;
            }
        }

        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_map<string,vector<pair<double,string>>>adj;

        for(int i=0;i<n;i++){
            adj[eq[i][0]].push_back({values[i],eq[i][1]});
            adj[eq[i][1]].push_back({(double)1/values[i],eq[i][0]});
        }

        vector<double>ans;
        
        for(auto &ele:queries){
            if(adj.find(ele[0])!=adj.end() && adj.find(ele[1])!=adj.end()){
                if(ele[1]==ele[0]){
                    ans.push_back(1);
                }else{
                    unordered_set<string>st;
                    ans.push_back(dfs(adj,st,ele[0],ele[1]));
                }
            }else{
                ans.push_back(-1.0);
            }
        }

        return ans;
    }
};
