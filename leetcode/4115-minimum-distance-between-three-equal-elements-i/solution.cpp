class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int mn = INT_MAX;

        for(auto &[key,val]:mp){
            int m = val.size();

            for(int i=0;i<m-2;i++){
                mn = min(mn, 2*(val[i+2])-2*(val[i]));
            }
        }

        return mn==INT_MAX?-1:mn;
    }
};


