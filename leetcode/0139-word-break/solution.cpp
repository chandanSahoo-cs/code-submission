class Solution {
public:
    // int dp[305][305];

    // int rec(string &s, unordered_set<string>&st, int l, int r){
    //     int n = s.size();
    //     if(r==n-1){
    //         if(st.find(s.substr(l,r-l+1))!=st.end()) return 1;
    //         return 0;
    //     }

    //     if(dp[l][r]!=-1) return dp[l][r];

    //     bool flag=false;

    //     if(st.find(s.substr(l,r-l+1))!=st.end()){
    //         flag |=rec(s,st,r+1,r+1);
    //     }

    //     flag |=rec(s,st,l,r+1);

    //     return dp[l][r] = flag;

    // }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool>curr(n);
        unordered_set<string>st(wordDict.begin(),wordDict.end());

       for(int l=0;l<n;l++){
        curr[l] = (st.find(s.substr(l,n-l))!=st.end());
       }

        for(int r=n-2; r>=0;r--){
            for(int l=r;l>=0;l--){
                if(st.find(s.substr(l,r-l+1))!=st.end()){
                    curr[l] = curr[l] || curr[r+1];
                }
            }
        }

        return curr[0];
    }
};
