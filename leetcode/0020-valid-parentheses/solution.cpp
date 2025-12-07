class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(auto ele:s){
            if(st.empty() && (ele!=')' || ele!='}' || ele!=']')) st.push(ele);
            else if(ele=='(' || ele=='{' || ele=='['){
                st.push(ele);
            }else{
                if(st.top()=='(' && ele==')') st.pop();
                else if(st.top()=='{' && ele=='}') st.pop();
                else if(st.top()=='[' && ele==']') st.pop();
                else break;    
            }
        }

        return st.size()==0;
    }
};
