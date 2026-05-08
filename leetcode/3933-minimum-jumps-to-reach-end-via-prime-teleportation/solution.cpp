int isPrime[1000005];
vector<int>bucket[1000005];

auto sieve = [](){
    memset(isPrime,1,sizeof(isPrime));
    
    isPrime[0] = isPrime[1] = 0;

    for(int i=2;i<1000005;i++){
        if(!isPrime[i]) continue;
        bucket[i].push_back(i);

        for(int j=2*i;j<1000005;j+=i){
            isPrime[j]=0;
            bucket[i].push_back(j);
        }
    }
    return 0;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        unordered_map<int,vector<int>>inBucket;
        unordered_map<int ,bool>done;
        for(int i=0;i<n;i++){
            if(isPrime[nums[i]] && !done.count(nums[i])){
                done[nums[i]]=true;
                for(auto v:bucket[nums[i]]){
                    if(mp.count(v)){
                        for(auto j:mp[v]){
                            inBucket[nums[i]].push_back(j);
                        }
                    }
                }
            }
        }

        vector<int>vis(n);

        queue<int>q;
        q.push(0);
        vis[0] = 1;

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

                if(isPrime[nums[u]]){
                    for(auto v:inBucket[nums[u]]){
                        if(vis[v]) continue;
                        q.push(v);
                        vis[v]=1;
                    }
                    inBucket[nums[u]].clear();
                }
            }
            level++;
        }

        return level;
    }
};
