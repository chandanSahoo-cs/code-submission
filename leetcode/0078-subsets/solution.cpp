class Solution {
public:
    vector<vector<int>>ans;

    void rec(vector<int>&nums, int i, vector<int>&temp){
        int n = nums.size();
        if(i==n){
            ans.push_back(temp);
            return;
        }

        rec(nums,i+1,temp);
        temp.push_back(nums[i]);
        rec(nums,i+1,temp);
        temp.pop_back();

        return;
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        rec(nums,0,temp);

        return ans;    
    }
};
