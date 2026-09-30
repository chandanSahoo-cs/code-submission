class Solution {
public:
    /*
    for i -> [0,n) :
        if seq[i]=='(' :
            int val = st.empty() ? 0: !st.top();
            ans[i] = val;
            st.push(val);
        else :
            ans[i] = st.top();
            st.pop();
    */

    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();

        stack<int>st;
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                int val = st.empty()?0:!st.top();
                ans[i] = val;
                st.push(val);
            }else{
                ans[i] = st.top();
                st.pop();
            }
        }

        return ans;
    }
};
