class Solution {
public:
    int maxArea(vector<int>& keep){
        int n = keep.size();

        stack<int>st;

        vector<int>next(n,n-1),prev(n,0);

        for(int i=0;i<n;i++){
            while(!st.empty() && keep[st.top()]>=keep[i]){
                st.pop();   
            }

            if(!st.empty()) prev[i] = st.top()+1;
            st.push(i);
        }

        st = stack<int>();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && keep[st.top()]>=keep[i]){
                st.pop();
            }
            if(!st.empty()) next[i] = st.top()-1;
            st.push(i);
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            int l = prev[i]==-1?i:prev[i];
            int r = next[i]==-1?i:next[i];

            ans=max(ans,(r-l+1)*keep[i]);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;
        vector<int>keep(m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    keep[j]+=1;
                }else keep[j]=0;
            }

            ans = max(ans,maxArea(keep));
        }

        return ans;
    }
};
