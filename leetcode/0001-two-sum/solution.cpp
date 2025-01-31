class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        for(int i=0;i<nums.size();i++){
            auto it = mp.find(target-nums[i]);
            if(it!=mp.end()){
                if(2*nums[i] == target && it->second.size()>1){
                    return {it->second[0],it->second[1]};

                }
                // if(2*nums[i]==target){
                //     if(it->second.size()>1){
                //         return {it->second[0],it->second[1]};
                //     }
                // }
                else if(2*nums[i]!=target) {
                    return {i,it->second.back()};
                }
            }
        }
        return {};
    }
};
