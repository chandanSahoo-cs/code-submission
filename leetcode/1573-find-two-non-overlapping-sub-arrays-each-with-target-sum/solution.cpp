class Solution {
public:

    int dp[100005][2];

    int rec(vector<int>&a, int i, int j){
        int n = a.size();
        if(j==2) return 0;
        if(i>=n) return INT_MAX;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = rec(a,i+1,j);
        
        if(a[i]!=-1){
            int p = rec(a,a[i]+1,j+1);
            if(p!=INT_MAX){
                ans = min(ans,a[i]-i+1+p);
            }
        }

        return dp[i][j] = ans;
    }

    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int>a(n,-1);

        int l = 0, r = 0;
        int sum = 0;

        while(r<n){
            sum+=arr[r];

            while(sum>target){
                sum-=arr[l];
                l++;
            }

            if(sum==target){
                a[l] = r;
            }

            r++;
        }

        memset(dp,-1,sizeof(dp));

        int ans = rec(a,0,0);
        return ans==INT_MAX?-1:ans;
    }
};
