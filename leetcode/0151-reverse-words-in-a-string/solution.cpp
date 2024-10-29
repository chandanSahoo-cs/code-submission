#define ll long long
class Solution {
public:
    string reverseWords(string s) {
        ll n = s.size();
        string ans = "";
        string temp = "";
        stack<string>st;

        for(ll i=0;i<n;i++){
            if(s[i]==' ' && temp!=""){
                st.push(temp);
                temp = "";
            }
            else{
                if(s[i]!=' ') temp+=s[i];
            }
        }
        if(temp!="") st.push(temp);

        while(!st.empty()){
            ans+=st.top();
            if(st.size()!=1){
                ans+=' ';
            }
            st.pop();
        }
        return ans.substr(0,n);
    }
};
