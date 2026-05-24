class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int alt = 0;


        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                alt++;
            }
        }

        if(alt>=2 && n-alt>=2) return -1;

        vector<int>rnums = nums;
        reverse(rnums.begin(),rnums.end());

        int cnt = 0;
        int k=0,rk=0;
        
        if(alt==1){
            for(int i=0;i<n;i++){
                if(nums[i]>nums[(i+1)%n]){
                    k=i;
                    break;
                }
            }
            
            for(int i=0;i<n;i++){
                if(rnums[i]<rnums[(i+1)%n]){
                    rk=i;
                    break;
                }
            }

            cnt+=min(k==n-1?0:k+1,rk==n-1?2:rk+3);
        }else{
            for(int i=0;i<n;i++){
                if(nums[i]<nums[(i+1)%n]){
                    k=i;
                    break;
                }
            }

            
            for(int i=0;i<n;i++){
                if(rnums[i]>rnums[(i+1)%n]){
                    rk=i;
                    break;
                }
            }
            
            cnt+=min(k==n-1?1:k+2,rk==n-1?1:rk+2);
        }

        return cnt;
    }
};
