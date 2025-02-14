class Solution {
public:
    vector<vector<int>>ans;

    void giveAns(vector<int> &nums, vector<int>&s, int indx){
        if(indx==nums.size()){
            ans.push_back(s);
            return;
        }
        s.push_back(nums[indx]);
        giveAns(nums,s,indx+1);
        s.pop_back();
        giveAns(nums,s,indx+1);

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>s;
        giveAns(nums,s,0);
        return ans;
    }
};
