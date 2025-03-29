class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            if(a[i]<0) st.push(a[i]);
            else if(a[i]>0){
                bool flag=true;
                while(!st.empty() && st.top()<0){
                    if(abs(st.top())==a[i]){
                        flag=false;
                        st.pop();
                        break;
                    }
                    else if(abs(st.top())>a[i]){
                        flag=false;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }

                if(flag) st.push(a[i]);
            }
        }

        vector<int>ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        // reverse(ans.begin(),ans.end());

        return ans;
    }
};
