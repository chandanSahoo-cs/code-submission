#define ll long long
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();

        ll ans = 0;
        ll prev = 0;
        
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                ll curr = nums[i-1]-nums[i];
                nums[i]+=curr;
        
                if(curr>prev){
                    ans+=curr-prev;
                }
                
                prev = curr;
            }else{
                prev = 0;
            }   
        }

        return ans;
    }
};
