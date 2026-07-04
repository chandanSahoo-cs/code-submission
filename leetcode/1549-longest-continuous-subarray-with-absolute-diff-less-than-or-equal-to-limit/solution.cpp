class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        deque<int>mxdq;
        deque<int>mndq;

        int l = 0, r =0;
        int mx = 0;

        while(r<n){
            while(!mxdq.empty() && nums[mxdq.front()]<nums[r]) mxdq.pop_front();
            mxdq.push_front(r);

            while(!mndq.empty() && nums[mndq.front()]>nums[r]) mndq.pop_front();
            mndq.push_front(r);

            while(nums[mxdq.back()]-nums[mndq.back()]>limit){
                if(mxdq.back()==l) mxdq.pop_back();
                if(mndq.back()==l) mndq.pop_back();
                l++;
            }

            mx = max(r-l+1,mx);
            r++;
        }

        return mx;
    }
};
