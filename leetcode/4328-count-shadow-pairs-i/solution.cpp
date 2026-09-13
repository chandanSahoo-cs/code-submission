#define ll long long

class Solution {
public:
    ll shadowPairs(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;

        ll cnt = 0;

        unordered_map<int,int>freq;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                freq[nums[st.top()]]--;
                st.pop();
            }

            cnt+=st.size()-(freq.count(nums[i])?freq[nums[i]]:0);
            freq[nums[i]]++;
            st.push(i);
        }

        return cnt;  
    }
};
