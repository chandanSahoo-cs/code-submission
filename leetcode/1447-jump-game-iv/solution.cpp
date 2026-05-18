class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        
        vector<int>vis(n);
        queue<int>q;

        q.push(0);
        vis[0]=1;

        int level = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int k=0;k<sz;k++){
                int u = q.front();
                q.pop();

                if(u==n-1) return level;

                if(u-1>=0 && !vis[u-1]){
                    q.push(u-1);
                    vis[u-1]=1;
                }

                if(u+1<n && !vis[u+1]){
                    q.push(u+1);
                    vis[u+1]=1;
                }


                while(mp[arr[u]].size()>0){
                    int ele = mp[arr[u]].back();
                    if(!vis[ele]){
                        q.push(ele);
                        vis[ele]=1;
                    }
                    mp[arr[u]].pop_back();
                }
            }
            level++;
        }

        return -1;
    }
};
