class Solution {
public: 
    vector<int> giveNext(vector<int>& a){
        int n = a.size();

        stack<int>st;
        vector<int>next(n,n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }
            if(!st.empty()) next[i]=st.top();
            st.push(i);
        }

        return next;
    }

    vector<int> givePrev(vector<int>& a){
        int n = a.size();

        stack<int>st;
        vector<int>prev(n,-1);

        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }
            if(!st.empty()) prev[i]=st.top();
            st.push(i);
        }

        return prev;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int>next = giveNext(heights);
        vector<int>prev = givePrev(heights);

        int mx=0;

        for(int i=0;i<n;i++){
            mx = max(mx,heights[i]*(next[i]-prev[i]-1));
        }

        return mx;
    }
};
