class Solution {
    int dp[1005][1005];
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans = 0;
                if(s1[i]==s2[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }

        vector<pair<int,int>>ind;

        int i=0,j=0;
        while(i<n && j<m){
            if(s1[i]==s2[j]){
                ind.push_back({i,j});
                i++,j++;
            }else if(dp[i+1][j]>=dp[i][j+1]){
                i++;
            }else{
                j++;
            }
        }

        i=0,j=0;

        string ans = "";

        for(int k=0;k<ind.size();k++){
            int pn = ind[k].first;
            int pm = ind[k].second;

            while(i<pn){
                ans.push_back(s1[i]);
                i++;
            }
            i++;
            while(j<pm){
                ans.push_back(s2[j]);
                j++;
            }
            j++;

            ans.push_back(s1[pn]);
        }

        while(i<n){
            ans.push_back(s1[i]);
            i++;
        }

        while(j<m){
            ans.push_back(s2[j]);
            j++;
        }

        return ans;


    }
};
