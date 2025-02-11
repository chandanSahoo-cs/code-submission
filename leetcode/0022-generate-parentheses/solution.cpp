class Solution {
public:
    void giveAns(int n, vector<string> &a, string s, int open, int close){
        if(s.size()==2*n && open==close){
            a.push_back(s);
            return;
        }

        if(open==close){
            giveAns(n,a,s+'(',open+1,close);
        }
        else{
            if(open<n){
                giveAns(n,a,s+'(',open+1,close);
            }
            if(close<n){
                giveAns(n,a,s+')',open,close+1);
            }
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        string s;
        vector<string>a;
        giveAns(n,a,s,0,0);

        return a;
    }
};
