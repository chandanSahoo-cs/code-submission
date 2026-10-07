class Solution {
public:
    unordered_set<string>st;
    int mx = INT_MIN;

    void rec(string &s,string &keep,int i, int cnt){
        int n = s.size();

        if(i==n){
            if(cnt==0){
                mx = max(mx,(int)keep.size());
                st.insert(keep);
            }
            return;
        }

        if(s[i]!='(' && s[i]!=')'){
            keep+=s[i];
            rec(s,keep,i+1,cnt);
            keep.pop_back();
        }else{
            int add = (s[i]=='('?1:-1);

            if(cnt+add>=0){
                keep+=s[i];
                rec(s,keep,i+1,cnt+add);
                keep.pop_back();
            }

            rec(s,keep,i+1,cnt);
        }

        return;
    }

    vector<string> removeInvalidParentheses(string s) {
        string keep = "";

        rec(s,keep,0,0);

        vector<string>ans;

        for(auto &ele:st){
            if(ele.size()==mx) ans.push_back(ele);
        }

        return ans;
    }
};
