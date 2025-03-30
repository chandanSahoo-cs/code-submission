class Solution {
public:

    vector<int>left(int n, vector<int>&a){

        stack<int>st;
        vector<int>ans(n,0);

        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            if(!st.empty()) ans[i]=st.top()+1;
            st.push(i);
        }

        return ans;
    }

    vector<int> right(int n, vector<int>&a){
        stack<int>st;
        vector<int>ans(n,n-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            if(!st.empty()) ans[i]=st.top()-1;
            st.push(i);
        }

        return ans;
    }

    int mx(int n, vector<int>&a){

        vector<int>l = left(n,a);
        vector<int>r = right(n,a);

        int ans=-1;

        for(int i=0;i<n;i++){
            ans = max(ans,a[i]*(i-l[i]+r[i]-i+1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>sum(m,0);
        int ans=-1;   
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') sum[j]=0;
                else sum[j]+=(matrix[i][j]-'0');
            }
            ans=max(ans,mx(m,sum));
        }

        return ans;
    }
};
