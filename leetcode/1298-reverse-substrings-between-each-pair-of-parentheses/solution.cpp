class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
    
        for(auto c:s){
            if(c!=')'){
                st.push(c);
            }else{
                string t = "";

                while(st.top()!='('){
                    t+=st.top();
                    st.pop();
                }
                st.pop();

                for(auto ele:t){
                    st.push(ele);
                }
            }
        }

        string ans="";

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};
