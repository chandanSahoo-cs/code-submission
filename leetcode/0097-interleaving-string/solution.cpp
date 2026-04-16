class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), l = s3.size();
        if(n+m!=l) return false;

        vector<bool>next(m+1,false),curr(m+1,false);
        next[m] = curr[m] = true;

        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n && j==m ) continue;
                bool flag = false;

                if(i<n && s1[i]==s3[i+j]){
                    flag |= next[j];
                }
                if(j<m && s2[j]==s3[i+j]){
                    flag |= curr[j+1];
                }

                curr[j]= flag;
            }

            next = curr;
        }

        return curr[0];
    }
};
