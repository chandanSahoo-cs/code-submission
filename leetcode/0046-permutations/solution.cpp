class Solution {
public:
    vector<vector<int>>ans;

    void rec(vector<int>& nums, vector<int> &used, int ind){
        int n = nums.size();

        if(ind==n){
            vector<int>temp;

            for(auto ele:used){
                temp.push_back(nums[ele]);
            }
            ans.push_back(temp);

            return;
        }

        int i=0;

        while(i<n){
            if(used[i]==-1){
                used[i]=ind;
                rec(nums,used,ind+1);
                used[i]=-1;
            }

            int temp = nums[i];
            
            while(i<n && nums[i]==temp) i++;
        }

        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>used(n,-1);
        
        rec(nums,used,0);

        return ans;
    }
};
