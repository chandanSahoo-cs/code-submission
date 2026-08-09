#define ll long long

class Solution {
public:
    ll weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>>adj(n);

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }

        queue<int>q;
        q.push(0);

        int h = 0;
        ll ans = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int i=0;i<sz;i++){
                int u = q.front();
                q.pop();

                ans-=nums[u]*1LL*(h+1);

                for(auto v:adj[u]){
                    q.push(v);
                }
            }
            h++;
        }

        ll sum = accumulate(nums.begin(),nums.end(),0LL);

        ans+=sum*(h+1);

        return ans;
    }
};
