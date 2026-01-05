class Solution {
public:
    vector<string>ans;
    int dp[305][305];

    bool rec(string &s, unordered_set<string>&st, int l, int r){
        int n = s.size();

        if(r==n-1){
            return st.count(s.substr(l,r-l+1));
        }

        if(dp[l][r]!=-1) return dp[l][r];

        bool flag=false;

        if(st.count(s.substr(l,r-l+1))){
            flag|=rec(s,st,r+1,r+1);
        }

        flag|=rec(s,st,l,r+1);

        return dp[l][r] = flag;
    }

    void give(string &s,unordered_set<string>&st, int l, int r, string keep){
        int n = s.size();

        string t = s.substr(l,r-l+1);
        if(r==n-1){
            if(st.count(t)){
                keep+=t;
                ans.push_back(keep);
                keep.erase(keep.size()-t.size());
            }

            return;
        }

        if(st.count(t)){
            if(rec(s,st,r+1,r+1)){
                keep+=t;
                keep.push_back(' ');

                give(s,st,r+1,r+1,keep);

                keep.erase(keep.size()-t.size());
                keep.pop_back();
            }
        }

        if(rec(s,st,l,r+1)){
            give(s,st,l,r+1,keep);
        }

        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string>st(wordDict.begin(),wordDict.end());

        memset(dp,-1,sizeof(dp));

        string keep = "";
        give(s,st,0,0,keep);

        return ans;
    }
};
