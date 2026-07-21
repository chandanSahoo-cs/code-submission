class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        int i = 0;
        int prev = 0;

        int active = 0;
        int mx = 0;

        while(i<n){
            
            int cntZero = 0;

            while(i<n && s[i]=='1') i++,active++;
            while(i<n && s[i]=='0') i++,cntZero++;

            if(prev!=0 && cntZero!=0){
                mx = max(mx,cntZero+prev);
            }

            prev = cntZero;
        }

        return active+mx;
    }
};
