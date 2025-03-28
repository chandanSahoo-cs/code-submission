class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> q;
        queue<int> mxq;
        multiset<int> st;

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(q.size()==k){
                ans.push_back(*st.rbegin());
                st.extract(q.front());
                q.pop();
            }
            q.push(nums[i]);
            st.insert(nums[i]);
        }
        ans.push_back(*st.rbegin());

        return ans;
    }
};
