class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        stack<int>st;

        st.push(-1);
        map<int,int>mp;

        for(int i=m-1;i>=0;i--){
            while(st.top()!=-1 && st.top()<=nums2[i]){
                st.pop();
            }
            mp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};
