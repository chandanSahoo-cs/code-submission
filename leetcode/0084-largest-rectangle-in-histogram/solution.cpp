class Solution {
public:
    vector<int>left(vector<int>&a){
        int n = a.size();
        stack<int>st;
        vector<int>ans(n,n-1);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top()-1;
            st.push(i);
        }

        return ans;
    }

    vector<int>right(vector<int>&a){
        int n = a.size();
        stack<int>st;
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top()+1;
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>l = left(heights);
        vector<int>r = right(heights);
        int mx = -1;
        int n = heights.size();
        for(int i=0;i<n;i++){
            mx = max(mx,heights[i]*(i-r[i]+l[i]-i+1));
        }
        return mx;
    }
};
