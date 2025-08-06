class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int i=0;
        int mx=0;

        int cnt=0;
        int jmp=0;
        while(i<n-1){
            int curr = nums[i];
            while(curr>0){
                if(mx<i+curr+nums[min(i+curr,n-1)]){
                    mx = max(mx,i+curr+nums[min(i+curr,n-1)]);
                    jmp=i+curr;

                }
                if(jmp>=n-1) break;
                curr--;
            }
            cnt++;
            mx=0;
            i=jmp;
        }

        return cnt;
    }
};
