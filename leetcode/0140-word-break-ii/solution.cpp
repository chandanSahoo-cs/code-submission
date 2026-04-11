class Solution {
public:
    vector<string>ans;
    int dp[25];
    bool rec(vector<string>& wordDict, string &s, int i){
        int n = s.size();

        if(i>=n) return true;

        if(dp[i]!=-1) return dp[i];

        
        for(auto &ele:wordDict){
            int m = ele.size();
            if(ele==s.substr(i,m) && rec(wordDict,s,i+m)){
                return dp[i]=true;
            }
        }

        return dp[i] = false; 
    }

    void print(vector<string> &wordDict, string &s, int i, string &path){
        int n = s.size();
        if(i>=n){
            ans.push_back(path);
            return;
        }

        for(auto &ele:wordDict){
            int m = ele.size();
            string temp = s.substr(i,m);
            if(ele==temp && rec(wordDict,s,i+m)){
                if(path.size()>0) path+=' ';
                path+=temp;
                print(wordDict,s,i+m,path);
                while(m--) path.pop_back();
                if(path.size()>1) path.pop_back();
            }
        }

        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        string path;
        print(wordDict,s,0,path);

        return ans;
    }
};
