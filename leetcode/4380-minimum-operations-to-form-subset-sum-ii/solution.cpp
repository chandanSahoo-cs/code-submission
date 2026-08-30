#define ll long long
class Solution {
public:

    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();

        vector<vector<int>>dp(n+1,vector<int>(sum+1));

        for(int j=0;j<=sum;j++) dp[n][j]=-1;
        for(int i=0;i<=n;i++) dp[i][sum]=0;


        for(int i=n-1;i>=0;i--){
            vector<pair<int,int>>poss;

            int steps = 0;
            queue<int>q;
            unordered_set<int>st;

            q.push(nums[i]);
            st.insert(nums[i]);

            poss.push_back({nums[i],0});

            while(!q.empty()){
                int sz = q.size();

                while(sz--){
                    int u = q.front();
                    q.pop();

                    if((u<<1)<=sum && !st.count(u<<1)){
                        st.insert(u<<1);
                        q.push(u<<1);
                        poss.push_back({u<<1,steps+1});
                    }

                    if((u>>1)>0 && !st.count(u>>1)){
                        st.insert(u>>1);
                        q.push(u>>1);
                        poss.push_back({u>>1,steps+1});
                    }
                }
                steps++;
            }

            for(int j=sum-1;j>=0;j--){
                int mn = dp[i+1][j];

                auto relax = [&](int p, int j){
                    if(p!=-1){
                        if(mn==-1) mn = j+p;
                        else mn = min(mn,j+p);
                    }
                };

                for(auto &[value,s]:poss){
                    if(value+j<=sum) relax(dp[i+1][value+j],s);
                }

                dp[i][j] = mn;
            }
        }

        return dp[0][0];
    }
};
