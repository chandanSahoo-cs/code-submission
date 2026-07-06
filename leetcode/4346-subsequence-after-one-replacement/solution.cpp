class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if(n>m) return false;

        vector<int>pref(n,m);
        vector<int>suff(n,-1);

        int i=0;

        for(int j=0;j<m;j++){
            if(i==n) break;
            if(s[i]==t[j]){
                pref[i]=j;
                i++;
            }
        }

        i = n-1;

        for(int j=m-1;j>=0;j--){
            if(i==-1) break;
            if(s[i]==t[j]){
                suff[i]=j;
                i--;
            }
        }
        
        for(int i=0;i<n;i++){
            int left = i==0?-1:pref[i-1];
            int right = i==n-1?m:suff[i+1];

            if(right-left>=2) return true;
        }
        
        return false;
    }
};
