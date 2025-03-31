class Solution {
public:
    int  left(int  n,vector<int> &a,int  r){
        stack<int >st;
        for(int  i=r-1;i>=0;i--){
            while(!st.empty() && a[st.top()]<a[i]){
                st.pop();
            }
            st.push(i);
        }
        
        int  ans = 0;
        int  i=0;
        while(i<r && !st.empty()){
            i = st.top()+1;
            int  curr = a[st.top()];
            st.pop();
            int  limit=r;
            if(!st.empty()) limit = st.top();
            while(i<limit){
                ans+=curr-a[i];
                i++;
            }
        }
        return ans;
    }
    
    int  right(int  n, vector<int>&a , int  r){
        stack<int >st;
        for(int  i=r+1;i<n;i++){
            while(!st.empty() && a[st.top()]<a[i]){
                st.pop();
            }
            st.push(i);
        }
        int  ans = 0;
        int  i=n-1;
        while(i>r && !st.empty()){
            i=st.top()-1;
            int  curr = a[st.top()];
            st.pop();
            int  limit = r;
            if(!st.empty()) limit = st.top();
            while(i>limit){
                ans+=curr-a[i];
                i--;
            }
        }
        return ans;
    }


    int trap(vector<int>& h) {
        int  n = h.size();
        int  mxInd = max_element(h.begin(),h.end())-h.begin();
        return left(n,h,mxInd)+right(n,h,mxInd);
    }
};
