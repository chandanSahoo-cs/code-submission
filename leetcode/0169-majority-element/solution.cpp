class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cnt=0;
        int curr = -1;

        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                curr = nums[i];
            }else{
                if(nums[i]==curr) cnt++;
                else cnt--;
            }
        }

        int keep=0;
        if(cnt>0){
            for(int i=0;i<n;i++){
                if(nums[i]==curr) keep++;
            }
        }

        if(keep>n/2) return curr;
        return -1;

    }
};
