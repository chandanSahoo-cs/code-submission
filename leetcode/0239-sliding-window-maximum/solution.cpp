class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int>dq;

        int i = 0;

        vector<int>ans;

        while(i<n){
            while(!dq.empty() && nums[dq.front()]<nums[i]) dq.pop_front();
            dq.push_front(i);

            while(!dq.empty() && dq.back()<i-k+1) dq.pop_back();

            if(i>=k-1) ans.push_back(nums[dq.back()]);
            i++;
        }

        return ans;
    }
};
