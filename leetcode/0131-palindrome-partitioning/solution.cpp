class Solution {
public:
    vector<vector<string>> ans;
    int dp[20][20];
    
    void fillDp(string&s){
        int n = s.size();

        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }

        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) dp[i][i+1] = 1;
            else dp[i][i+1]=0;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i+1>=j){
                    // if(i+1!=j && i!=j) dp[i][j]=0;
                    continue; 
                }
                dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
            }
        }
    }

    void rec(string &s, int l, int i, vector<string> &tv){
        int n = s.size();

        if(i==n-1){
            if(dp[l][i]==1){
                tv.push_back(s.substr(l));
                ans.push_back(tv);
                tv.pop_back();
            }
            return;
        }
        if(dp[l][i]==1){
            tv.push_back(s.substr(l,i-l+1));
            rec(s,i+1,i+1,tv);
            tv.pop_back();
        }

        rec(s,l,i+1,tv);



        return ;
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        fillDp(s);

        vector<string> tv;
        rec(s,0,0,tv);


        return ans;
    }
};
