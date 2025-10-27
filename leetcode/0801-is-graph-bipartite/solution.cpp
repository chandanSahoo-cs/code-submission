class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        stack<int>st;
        vector<int>vis(n);
        vector<int>color(n);

        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            st.push(i);
            color[i]=0;

            while(!st.empty()){
                int ele = st.top();
                st.pop();
                vis[ele]=1;
                int col = color[ele];

                for(auto e:graph[ele]){
                    if(vis[e]){
                        if(color[e]==col) return false;
                    }else{
                        st.push(e);
                        color[e]=!col;
                    }
                }
            }
        }
        return true;
    }
};
