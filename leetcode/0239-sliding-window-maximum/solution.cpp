class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(i>k-1){
                if(nums[i-k]==dq.front()) dq.pop_front();
            }
            while(!dq.empty() && dq.back()<nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            if(i>=k-1){
                ans.push_back(dq.front());  
            }
        }

        return ans;
    }
};
