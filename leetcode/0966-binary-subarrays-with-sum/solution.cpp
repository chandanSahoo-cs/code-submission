class Solution {
public:
    int give(int n, vector<int>&a, int x){
        int l=0,r=0;
        int cnt=0;
        int sum=0;
        int prev=-1;

        while(r<n){
            sum+=a[r];
            while(l<r && sum>x){
                sum-=a[l];
                l++;
            }
            if(sum==x){
                int k = r-l+1;
                int m = prev-l+1;
                int rem=0;
                if(m>0){
                    rem = (m*(m+1))/2;
                }
                cnt+=(k*(k+1))/2-rem;
                prev=r;
            }
            r++;
        }

        return cnt;
    }


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return max(0,give(n,nums,goal)-give(n,nums,goal-1));
    }
};
