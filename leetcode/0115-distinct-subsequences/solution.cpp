class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        vector<long long>next(m+1), curr(m+1);
        next[m]=curr[m]=1;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int cnt = next[j];
                if(s[i]==t[j]){
                    cnt+=next[j+1];
                }

                curr[j] = cnt;
            }
            next = curr;
        }

        return next[0];
    }
};
