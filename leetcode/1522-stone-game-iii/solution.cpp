class Solution {
public:
    string stoneGameIII(vector<int>& s) {
        int n = s.size();
        vector<int>suff = s;

        for(int i=n-2;i>=0;i--){
            suff[i]+=suff[i+1];
        }

        vector<int>dp(n+1);

        for(int i=n-1;i>=0;i--){
            int mx = s[i]+(i+1<n?suff[i+1]-dp[i+1]:0);
            
            if(i+1<n){
                mx = max(mx,s[i]+s[i+1]+(i+2<n?suff[i+2]-dp[i+2]:0));
            }
            if(i+2<n){
                mx = max(mx,s[i]+s[i+1]+s[i+2]+(i+3<n?suff[i+3]-dp[i+3]:0));
            }
            dp[i] = mx;
        }

        int ans = dp[0];

        if(2*ans>suff[0]) return "Alice";
        else if(2*ans<suff[0]) return "Bob";
        
        return "Tie";
    }
};
