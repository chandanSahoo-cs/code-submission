class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        

        for(auto ele:s){
            if(st.empty()) st.push(ele);
            else if(st.top()=='(' && ele==')') st.pop();
            else if(st.top()=='{' && ele=='}') st.pop();
            else if(st.top()=='[' && ele==']') st.pop();
            else st.push(ele);
        }

        return st.size()==0;
    }
};
