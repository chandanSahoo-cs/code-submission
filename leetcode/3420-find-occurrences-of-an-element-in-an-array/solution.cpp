class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        
        vector<int>store;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==x) store.push_back(i);
        }

        vector<int>ans;

        for(auto ele:queries){
            if(ele-1>=store.size()){
                ans.push_back(-1);
            }else{
                ans.push_back(store[ele-1]);
            }
        }

        return ans;
    }
};
