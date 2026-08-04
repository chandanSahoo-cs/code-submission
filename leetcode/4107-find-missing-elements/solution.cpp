class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX,mx = INT_MIN;
        unordered_set<int>st;

        for(auto ele:nums){
            mn = min(mn,ele);
            mx = max(mx,ele);
            st.insert(ele);
        }

        vector<int>ans;
        for(int i=mn;i<=mx;i++){
            if(!st.count(i)) ans.push_back(i);
        }

        return ans;
    }
};
