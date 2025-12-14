class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int>curr(m+1,0),prev(m+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){

                if(s1[i]==s2[j]){
                    curr[j] = max(curr[j],1+prev[j+1]);
                }
                curr[j] = max(curr[j],prev[j]);
                curr[j] = max(curr[j],curr[j+1]);
            }
            prev = curr;
            curr.resize(m+1,0);
        }

        return prev[0];
    }
};
