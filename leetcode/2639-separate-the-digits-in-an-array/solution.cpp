class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;

        for(auto ele:nums){
            vector<int>temp;
            while(ele){
                temp.push_back(ele%10);
                ele/=10;
            }

            while(temp.size()){
                ans.push_back(temp.back());
                temp.pop_back();
            }
        }

        return ans;
    }
};
