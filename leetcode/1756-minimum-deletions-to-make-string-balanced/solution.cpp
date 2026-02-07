class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        vector<int>suff(n+1);

        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1]+(s[i]=='a');
        }

        int i = 0;
        int mn = n;
        int bCnt = 0;

        while(i<n){
            mn = min(bCnt+suff[i],mn);
            bCnt+=s[i]=='b';
            i++;
        }

        mn = min(mn,bCnt);

        return mn;
    }
};
