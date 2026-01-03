class Solution {
public:
    vector<vector<string>> ans;
    int dp[16][16];
    
    int checkPalindrome(string&s, int l, int r){
        if(r-l==0) return 1;
        if(r-l==1){
            if(s[l]==s[r]) return 1;
            else return 0;
        }

        if(dp[l][r]!=-1) return dp[l][r];
        return dp[l][r] = s[l]==s[r] && checkPalindrome(s,l+1,r-1);
    }

    void rec(string s, int l, int i, vector<string> &tv){
        int n = s.size();

        if(i==n-1){
            if(checkPalindrome(s,l,i)){
                tv.push_back(s.substr(l));
                ans.push_back(tv);
                tv.pop_back();
            }
            return;
        }
        rec(s,l,i+1,tv);

        if(checkPalindrome(s,l,i)){
            tv.push_back(s.substr(l,i-l+1));
            rec(s,i+1,i+1,tv);
            tv.pop_back();
        }


        return ;
    }

    vector<vector<string>> partition(string s) {
        memset(dp,-1,sizeof(dp));
        vector<string> tv;
        rec(s,0,0,tv);

        return ans;
    }
};
