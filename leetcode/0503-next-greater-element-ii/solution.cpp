class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>tnum(2*n);

        for(int i=0;i<n;i++){
            tnum[i]=tnum[i+n]=nums[i];
        }

        stack<int>st;

        vector<int>ans(n,-1);
        for(int i=tnum.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=tnum[i]){
                st.pop();
            }
            // if(ans[i%n]==-1){
                if(!st.empty()) ans[i%n]=st.top();
            // }
            st.push(tnum[i]);
        }

        return ans;
    }
};
