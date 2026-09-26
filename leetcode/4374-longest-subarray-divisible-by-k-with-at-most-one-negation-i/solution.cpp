class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        for(int l=0;l<n;l++){
            unordered_set<int>st;
            st.insert(0);

            int sum = 0;
            for(int r=l;r<n;r++){
                st.insert(((2*nums[r])%k+k)%k);
                sum+=nums[r];

                int req1 = (sum%k+k)%k;

                if(st.count(req1)){
                    ans = max(ans,r-l+1);
                }
            }
        }

        /*
        (sum-nums[i]-nums[i])%k==0;
        (sum-2*nums[i])%k=0;
        sum%k=(2*nums[i])%k;
        */

        return ans;
    }
};
