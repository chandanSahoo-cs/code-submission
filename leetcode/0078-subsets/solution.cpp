class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int m = pow(2,nums.size());
        vector<vector<int>>ans;

        for(int i=0;i<m;i++){
            int j = i;
            vector<int>temp;
            int k=0;
            while(j){
                if(j&1) temp.push_back(nums[k]);
                j>>=1;
                k++;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
