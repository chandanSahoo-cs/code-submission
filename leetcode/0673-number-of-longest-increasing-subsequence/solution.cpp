class Solution {
public:
    int search(vector<int>&a, int val){
        int n = a.size();

        int l = 0, r=n-1;
        int ans = n-1;

        while(l<=r){
            int m = l+(r-l)/2;

            if(a[m]<val){
                l = m+1;
            }else{
                r=m-1;
                ans = m;
            }
        }

        return ans;
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>insert(n,1e9),mark(n);
        vector<int>cnt(n,1);
        int sz = -1;

        for(int i=0;i<n;i++){
            int ind = search(insert,nums[i]);
            insert[ind] = nums[i];
            mark[i] = ind+1;
            sz = max(sz,mark[i]);

            int keep = 0;
            for(int j=0;j<=i;j++){
                if(mark[j]==ind && nums[i]>nums[j]) keep+=cnt[j];
            }
            cnt[i] = max(cnt[i],keep);
        }

        int tot = 0;

        for(int i=0;i<n;i++){
            if(mark[i]==sz){
                tot+=cnt[i];
            }
        }

        return tot;
    }
};
