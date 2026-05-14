class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(auto ele:nums){
            mp[ele]++;
        }

        for(int i=1;i<=n-2;i++){
            if(!mp.count(i)) return false;
        }


        if(!mp.count(n-1) || mp[n-1]<2) return false;

        return true;
    }
};
