#define ll long long
class Solution {
public:
    string removeOuterParentheses(string s) {
        ll n = s.size();
        stack<char>st;
        string ans = "";
        for(ll i=0;i<n;i++){
            if(!st.size()){
                st.push('(');
            }
            else if(st.top()=='('){
                if(s[i]=='('){
                    ans+='(';
                    st.push('(');
                }
                else{
                    if(st.size()!=1){
                        ans+=')';
                    }
                    st.pop();
                }
            }
        }
        return ans;
    }
};
