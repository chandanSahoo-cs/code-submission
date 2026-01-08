class Solution {
public:
    long long dp[505][505];
    int mark[505][505];

    long long rec(vector<int>& nums1, vector<int>& nums2, int i, int j){
        int n = nums1.size();
        int m = nums2.size();

        if(i==n || j==m){
            return 0;
        }

        if(mark[i][j]) return dp[i][j];
    
        long long ans = nums1[i]*1LL*nums2[j] + max(0LL,rec(nums1,nums2, i+1,j+1));

        if(j+1<m){
            ans = max(ans,rec(nums1,nums2,i,j+1));
        }

        if(i+1<n){
            ans = max(ans,rec(nums1,nums2,i+1,j));
        }

        mark[i][j] = 1;
        return dp[i][j] = ans;

    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return rec(nums1,nums2,0,0);    
    }
};
