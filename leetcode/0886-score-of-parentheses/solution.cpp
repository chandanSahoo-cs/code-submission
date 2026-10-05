class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();

        stack<int>st;

        int ans = 0;
        int curr = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(0);
            }else{
                int t = st.top();
                st.pop();

                int keep;
                if(t==0){
                    keep = 1;
                }else{
                    keep = t*2;
                }

                if(st.empty()){
                    st.push(keep);
                }else{
                    int temp = st.top();
                    st.pop();
                    st.push(temp+keep);
                }
            }
        }

        return st.top();
    }
};
