class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int n = nums.size();

        int mn = INT_MAX;

        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                if(x==y) continue;
                int cnt = 0;

                for(int i=0;i<n;i++){
                    int m = nums[i]%k;
                    int t = (i&1)?y:x;

                    int diff = abs(t-m);

                    cnt+=min(diff,k-diff);
                }

                mn = min(mn,cnt);
            }
        }

        return mn;
    }
};
