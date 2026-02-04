class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        if (s[0] == '0')
            return 0;
        dp[0] = 1;
        if(n==1 )return dp[0];
        int x = s[0] - '0';
        x = x * 10 + (s[1] - '0');
        if(x == 10 || x == 20 || (x>= 27 && x % 10 !=0 )
          )dp[1] = 1;
        else if(x>10 && x <27 )dp[1] = 2;
        else if(x>= 27 && x % 10 ==0 )dp[1]=0;
        if(dp[1] == 0) return 0;
        x = (s[1] - '0');
        
        for (int i = 2; i < n; i++) {
        
            x = x * 10 + (s[i] - '0');
                if (x < 27 && x >= 10)
                    dp[i] = dp[i - 1] + dp[i-2];
                else
                    dp[i] = dp[i - 1];
                x = (s[i] - '0');
            if(x == 0)
            {
                dp[i] -= dp[i-1];
                if(dp[i] <= 0) return dp[i] ;
                
            }
        }

        return dp[n - 1];
    }
};
