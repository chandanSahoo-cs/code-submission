class Solution {
public:

    vector<string>ans;

    void generate(int n, string &s, int o, int c){
        if(o+c==2*n){
            ans.push_back(s);
            return;
        }

        if(o<n){
            s+='(';
            generate(n,s,o+1,c);
            s.pop_back();
        }
        if(c<o){
            s+=')';
            generate(n,s,o,c+1);
            s.pop_back();
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        generate(n,s,0,0);

        return ans;
    }
};
