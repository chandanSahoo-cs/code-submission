class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int>one,two,three;

        for(int i=0;i<n;i++){
            one.insert(nums[i]);

            for(auto ele:one){
                two.insert(ele^nums[i]);
            }
        }

        for(auto ele:two){
            for(int i=0;i<n;i++){
                three.insert(ele^nums[i]);
            }
        }

        return three.size();
    }
};
