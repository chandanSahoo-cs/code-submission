class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int>nextg(m,-1);
        map<int,int>mp;

        stack<int>st;

        for(int i=m-1;i>=0;i--){
            mp[nums2[i]]=i;
            while(!st.empty() && nums2[st.top()]<=nums2[i]){
                st.pop();
            }

            if(!st.empty()) nextg[i] = st.top();

            st.push(i);
        }

        vector<int>ans;

        for(auto ele:nums1){
            int ind = nextg[mp[ele]];
            if(ind==-1){
                ans.push_back(-1);
            }else {
                ans.push_back(nums2[ind]);
            }
        }

        return ans;
    }
};
