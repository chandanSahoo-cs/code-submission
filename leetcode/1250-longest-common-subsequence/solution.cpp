class Solution {
public:
    int dp[1005][1005];

    int rec(string &s1, string &s2,int i,int j){
        int n = s1.size();
        int m = s2.size();

        if(i>=n || j>=m){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;

        if(s1[i]==s2[j]){
            ans = 1+rec(s1,s2,i+1,j+1);
        }else{
            int frst = rec(s1,s2,i+1,j);
            int scnd = rec(s1,s2,i,j+1);
            ans = max(frst,scnd);
        }

        return dp[i][j]=ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }
        return rec(text1,text2,0,0);
    }
};
