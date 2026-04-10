class Solution {
public:
    int compute(string &s, int l, int r){
        int n = s.size();
        int cnt = 0;

        while(l>=0 && r<=n-1 && s[l]==s[r]){
            l--,r++;
            cnt++;
        }

        return cnt;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            cnt+=compute(s,i,i);
            if(i>0){
                cnt+=compute(s,i-1,i);
            }
        }

        return cnt;
    }
};
