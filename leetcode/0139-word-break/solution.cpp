class Solution {
public:
    bool fn(int i, int j, unordered_set<string>&c, string &s,vector<vector<int>> &mark){
        if(j==s.size()-1){
            return (c.find(s.substr(i,j-i+1))!=c.end());
        }
        bool a1=false,a2=false;
        if(j-i+1>20) return false;
        if(mark[i][j]!=-1 ) return mark[i][j];
        if(c.find(s.substr(i,j-i+1))!=c.end()){
            a1 = fn(i,j+1,c,s,mark);
            a2 = fn(j+1,j+1,c,s,mark);
        }
        else a1 = a2 = fn(i,j+1,c,s,mark);
        return mark[i][j] = a1 || a2;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>>mark(s.size(),vector<int>(s.size(),-1));
        unordered_set<string> c(wordDict.begin(),wordDict.end());
        return fn(0,0,c,s,mark);
    }
};
