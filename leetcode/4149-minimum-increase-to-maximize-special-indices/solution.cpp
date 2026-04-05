#define ll long long

class Solution {
public:
    ll minIncrease(vector<int>& nums) {
        int n = nums.size();
        vector<pair<ll,ll>>dp(n+2);

        dp[n] = {0,0};
        dp[n+1] = {0,0};

        for(int i=n-2;i>=1;i--){
            ll left = 0, right = 0;

            if(i>0){
                left = nums[i-1]-nums[i]+1;
            }
            if(i<n-1){
                right = nums[i+1]-nums[i]+1;
            }

            ll ops = max(0LL,max(left,right));

            pair<ll,ll> p = dp[i+2];
            pair<ll,ll> np = dp[i+1];

            if(p.second+1>np.second){
                dp[i] = {ops+p.first,p.second+1};
            }else if(p.second+1<np.second){
                dp[i] = np;
            }else{
                dp[i] = {min(ops+p.first,np.first),np.second};
            }

        }
        
        return dp[1].first;
    }
};
