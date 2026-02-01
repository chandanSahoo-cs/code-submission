class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int>buckets(55);

        for(auto ele:nums){
            buckets[ele]++;
        }

        int sum = nums[0];
        buckets[nums[0]]--;
        int k = 2;

        for(int i=1;i<55;i++){
            while(buckets[i] && k){
                sum+=i;
                buckets[i]--;
                k--;
            }

            if(k==0) break;
        }

        return sum;
    }
};
