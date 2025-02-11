class Solution {
public:
    void giveAns(int n ,vector<string> &a, string s){
        if(s.size()==n){
            a.push_back(s);
            return;
        }
        if(s.empty() || s.back()=='1'){
            giveAns(n,a,s+'0');
            giveAns(n,a,s+'1');
        }
        else{
            giveAns(n,a,s+'1');
        }
        return;
    }

    vector<string> validStrings(int n) {
        vector<string>a;
        giveAns(n,a,"");

        return a;
    }
};
