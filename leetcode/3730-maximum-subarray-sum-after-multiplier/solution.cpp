#define ll long long

class Solution {
public:
    ll dp[100005][4];
    ll mark[100005][4];

    ll mx = LLONG_MIN;

    ll divide(int n, int k){
        if(n>=0) return n/k;

        return -(abs(n)/k);
    }

    ll rec(vector<int>&nums, int k, int i, int s){
        int n = nums.size();

        if(i==n) return 0;

        if(mark[i][s]) return dp[i][s];

        ll ans = 0;

        if(s==1 || s==2){
            ll p1 = rec(nums, k, i+1,s);
            ll p2 = rec(nums, k, i+1,3);

            ans = s==1?nums[i]*1LL*k:divide(nums[i],k);

            ans = max(ans,ans+0LL+max(p1,p2)); 
        }else if(s==0){
            ans = nums[i];
            ll p=0;
            for(int j=0;j<4;j++){
                p = max(p,rec(nums,k,i+1,j));
            }

            ans = max(ans,ans+0LL+p);
        }else{
            ans = nums[i];
            ans = max(ans,ans+0LL+rec(nums,k,i+1,3));
        }

        mx = max(ans,mx);
        mark[i][s]=1;
        return dp[i][s] = ans;
    }

    ll maxSubarraySum(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        memset(mark,0,sizeof(mark));

        for(int i=0;i<4;i++){
            rec(nums,k,0,i);
        }

        return mx;            
    }
};
