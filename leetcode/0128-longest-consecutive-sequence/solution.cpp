class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());

        int n = nums.size();
        int mx=0;

        for(auto ele:st){
            if(st.find(ele-1)==st.end()){
                int tr = ele;
                int cnt=0;
                while(st.find(tr)!=st.end()){
                    tr++;
                    cnt++;
                }
                mx = max(cnt,mx);
            }
        }

        return mx;
    }
};
