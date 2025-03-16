class Solution {
public:
    vector<string>ans;
    void solve(string &n, int t, string &s, int prevDigit, long long currSum, int indx){
        if(indx==n.size()){
            if(currSum==t){
                ans.push_back(s);
            }
            return;
        }
        for(int i=indx;i<n.size();i++){
            string part = n.substr(indx,i-indx+1);
            if(part.size()>1 && part[0]=='0') break;

            long long num = stoll(part);

            if(indx==0){
                s+=part;
                solve(n,t,s,num,num,i+1);
                s.erase(s.size()-part.size());
                continue;
            }

            //For*;
            s+='*';
            s+=part;
            solve(n,t,s,prevDigit*num,currSum-prevDigit+(prevDigit*num),i+1);
            s.erase(s.size()-part.size()-1);

            //For+;
            s+='+';
            s+=part;
            solve(n,t,s,num,currSum+num,i+1);
            s.erase(s.size()-part.size()-1);

            //For-;
            s+='-';
            s+=part;
            solve(n,t,s,-num,currSum-num,i+1);
            s.erase(s.size()-part.size()-1);

        }

        return;
    }
    vector<string> addOperators(string n, int t) {
        string s="";
        solve(n,t,s,0,0,0);
        return ans;
    }
};
