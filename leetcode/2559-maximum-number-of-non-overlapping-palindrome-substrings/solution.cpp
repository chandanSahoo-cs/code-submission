class Solution {
public:

    int dp[2005];

    int rec(vector<vector<int>>&a, int k, int i){
        int n = a.size();

        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int mx = rec(a,k,i+1);
        for(auto j:a[i]){
            if(j-i+1>=k){
                mx = max(mx,1+rec(a,k,j+1));
            }
        }

        return dp[i] = mx;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<int>>a(n);
        auto compute = [&](int l , int r){
            while(l>=0 && r<n && s[l]==s[r]){
                a[l].push_back(r);
                l--;
                r++;
            }
        };

        for(int i=0;i<n;i++){
            int l = i, r = i;

            compute(i,i);
            compute(i,i+1);
            
        }

        memset(dp,-1,sizeof(dp));

        return rec(a,k,0);
    }
};
