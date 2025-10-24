class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int>vis(n);
        queue<int>q;

        int cnt = 0;

        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            q.push(i);
            cnt++;

            while(!q.empty()){
                int ele = q.front();
                vis[ele]=1;
                q.pop();

                for(int j=0;j<n;j++ ){
                    if(isConnected[ele][j] && !vis[j]){
                        q.push(j);
                    }
                }
            }    
        }

        return cnt;
    }
};
