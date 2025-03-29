class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;

        for(int i=0;i<n;i++){
            while(k && !st.empty() && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        string ans = "";

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        int l=0;
        while(ans[l]=='0'){
            l++;
        }
        string a = ans.substr(l);
        int m = a.size()-k;
        return m<=0?"0":a.substr(0,m);
    }
};
