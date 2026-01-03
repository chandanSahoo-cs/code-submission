class Solution {
public:
    vector<vector<int>>ans;

    void rec(vector<int>&nums, int i, vector<int>&temp, int ignore){
        int n = nums.size();

        if(i==n){
            ans.push_back(temp);
            return;
        }

        if(nums[i]==ignore){
            rec(nums,i+1,temp,ignore);
            return;
        }

        rec(nums,i+1,temp,nums[i]);
        temp.push_back(nums[i]);
        rec(nums,i+1,temp,11);
        temp.pop_back();

        return ;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        rec(nums,0,temp,11);

        return ans;    
    }
};
