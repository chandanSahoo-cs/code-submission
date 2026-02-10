class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();


        int len = 0;

        for(int i=0;i<n;i++){

            unordered_set<int>st;
            int odd = 0;
            int even = 0;

            for(int j=i;j<n;j++){
                if(!st.count(nums[j])){
                    if(nums[j]&1) odd++;
                    else even++;
                    st.insert(nums[j]);
                }

                
                if(odd==even){
                    len = max(len,j-i+1);
                }
            }
        }

        return len;
    }
};
