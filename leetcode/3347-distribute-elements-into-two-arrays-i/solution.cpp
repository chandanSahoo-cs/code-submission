class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>a,b;

        int i = 0;
        a.push_back(nums[i++]);
        b.push_back(nums[i++]);

        while(i<n){
            if(a.back()>b.back()){
                a.push_back(nums[i++]);
            }else b.push_back(nums[i++]);
        }

        vector<int>ans(a.begin(),a.end());
        ans.insert(ans.end(),b.begin(),b.end());

        return ans;
    }
};
