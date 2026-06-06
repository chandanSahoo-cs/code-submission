#define ll long long 

class Solution {
public:
    ll dp[100005][2];

    ll rec(vector<int>&nums, string&s, int i, bool prev){
        int n = nums.size();

        if(i==n) return 0;

        if(dp[i][prev]!=-1) return dp[i][prev];

        ll mx = 0;
        if(s[i]=='1'){
            mx = max(mx,nums[i]+rec(nums,s,i+1,true));
            if(!prev && i>0){
                mx = max(mx,nums[i-1]+rec(nums,s,i+1,false));
            }
        }else mx = rec(nums,s,i+1,false);

        return dp[i][prev] = mx;
    }

    ll maxTotal(vector<int>& nums, string s) {
        memset(dp,-1,sizeof(dp));

        return rec(nums,s,0,false);
    }
};

/*
if not taken prev
    - stay on current and pass i+1, true
    - go back and pass i+1,false

if take prev
    - stay on current and pass i+1, true

*/
