class Solution {
public:

    string reverseParentheses(string s) {
        int n = s.size();

        stack<char>st;

        for(auto ele:s){
            if(ele!=')'){
                st.push(ele);
            }else{
                vector<char>temp;

                while(st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();

                for(auto ele:temp){
                    st.push(ele);
                }
            }
        }

        string ans = "";
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
