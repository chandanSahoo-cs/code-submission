class Solution {
public:
    vector<vector<int>>ans;

    void rec(vector<int>& nums, vector<int> &used, int ind, vector<int>&temp){
        int n = nums.size();

        if(ind==n){
            ans.push_back(temp);
            return;
        }

        int i=0;

        while(i<n){
            if(!used[i]){
                used[i]=1;
                temp.push_back(nums[i]);
                rec(nums,used,ind+1,temp);
                used[i]=0;
                temp.pop_back();

                int t = nums[i];
                
                while(i<n && t==nums[i]) i++;
            }else i++;
        }

        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>used(n);
        vector<int>temp;
        
        rec(nums,used,0,temp);

        return ans;
    }
};
