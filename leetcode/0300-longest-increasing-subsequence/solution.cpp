class Solution {
    int search(vector<int>&a, int val){
        int l=0,r=a.size()-1;
        int ind=a.size();

        while(l<=r){
            int m = l+(r-l)/2;
            if(a[m]<val){
                l=m+1;
            }else{
                ind=m;
                r=m-1;
            }
        }

        return ind;
    }

public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int>dp(n,1e9);

        for(int i=0;i<n;i++){
            int ind = search(dp,a[i]);
            dp[ind] = a[i];
        }

        int ans=1;

        for(int i=0;i<n && dp[i]<1e9;i++){
            ans=i+1;
        }

        return ans;

    }
};

