class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size();

        sort(a.begin(),a.end());
        vector<int>ans;

        vector<vector<int>>dp(n+2,vector<int>(n+1));

        for(int prev=0;prev<n+1;prev++){
            dp[n+1][prev] = 0;
        }

        for(int curr=n;curr>0;curr--){
            for(int prev=n;prev>=0;prev--){
                int ans=dp[curr+1][prev];
                if(prev==0 || a[curr-1]%a[prev-1]==0){
                    ans = max(ans,1+dp[curr+1][curr]);
                }
                dp[curr][prev] = ans;
            }
        }

        int curr=1, prev=0;

        while(curr<n+1){
            if((prev==0 || a[curr-1]%a[prev-1]==0) && 1+dp[curr+1][curr]>=dp[curr+1][prev]){
                ans.push_back(a[curr-1]);
                prev=curr;
                curr=curr+1;
            }else{
                curr=curr+1;
            }
        }

        return ans;
    }
};
