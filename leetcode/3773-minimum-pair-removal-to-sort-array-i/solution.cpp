class Solution {
public:

    pair<int,int>mnPair(vector<int>&nums){
        int n = nums.size();

        int mn = INT_MAX;

        int p1=-1,p2=-1;

        for(int i=0;i<n-1;i++){
            if(nums[i]+nums[i+1]<mn){
                p1=i;
                p2=i+1;
                mn = nums[i]+nums[i+1];
            }
        }

        return {p1,p2};
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        
        while(!is_sorted(nums.begin(),nums.end())){
            auto [p1,p2] = mnPair(nums);
            int sum = nums[p1]+nums[p2];
            nums.erase(nums.begin()+p1,nums.begin()+p2+1);
            nums.insert(nums.begin()+p1,sum);
            ops++;
        }

        return ops;
    }
};
