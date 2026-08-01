class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt0=0, cnt1=0;
        int cnt = 0;
        
        for(auto c:s){
            cnt0+=(c=='0');
            cnt1+=(c=='1');

            if(abs(cnt0-cnt1)<=1) cnt++;
        }

        return cnt;
    }
};
