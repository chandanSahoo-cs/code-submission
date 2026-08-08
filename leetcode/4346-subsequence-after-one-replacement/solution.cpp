class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if(n>m) return false;

        vector<int>pref(n,m);
        vector<int>suff(n,-1);

        int i = 0;

        for(int j=0;j<m;j++){
            if(s[i]==t[j]){
                pref[i] = j;
                i++;
            }
            if(i>=n) break;
        }

        i = n-1;

        for(int j=m-1;j>=0;j--){
            if(s[i]==t[j]){
                suff[i] = j;
                i--;
            }

            if(i<0) break;
        }

        for(int i=0;i<n;i++){
            int left = i-1<0?-1:pref[i-1];
            int right = i+1==n?m:suff[i+1];

            if(right-left>=2) return true;
        }   

        return false;
    }
};
