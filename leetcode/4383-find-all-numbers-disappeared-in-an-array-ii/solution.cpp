class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int>st(nums.begin(),nums.end());

        vector<vector<int>>ans;

        int l = lower;

        while(l<=upper){
            int strt = l;

            while(l<=upper && !st.count(l)){
                l++;
            }

            if(strt!=l){
                ans.push_back({strt,l-1});
            }
            l++;
        }

        return ans;
    }
};
