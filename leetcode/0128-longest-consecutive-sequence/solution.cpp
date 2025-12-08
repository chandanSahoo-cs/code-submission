class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());

        int mx = 0;

        for(auto ele:st){
            if(st.find(ele-1)==st.end()){
                int cnt=0;
                int tr = ele;
                while(st.find(tr)!=st.end()){
                    cnt++;
                    tr++;
                }
                mx = max(mx,cnt);
            }
        }

        return mx;
    }
};
