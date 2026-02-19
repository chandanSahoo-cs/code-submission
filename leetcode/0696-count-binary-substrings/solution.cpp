class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int n = s.size();

        int cnt = 1;
        int prevCnt = 0;

        int ans = 0;

        int i = 1;

        while(i<=n){

            while(i<n && s[i]==s[i-1]){
                cnt++;
                i++;
            }

            ans+=min(prevCnt,cnt);
            prevCnt = cnt;
            cnt=1;
            i++;
        }

        return ans;
    }
};
