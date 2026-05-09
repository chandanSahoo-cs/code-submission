class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int cnt1 = 0, cnt0 = 0;

        for(auto &c:s){
            cnt1+=(c=='1');
            cnt0+=(c=='0');
        }

        if(s[0]=='1' && s[n-1]=='1'){
            return min(max(0,cnt1-2),cnt0);
        }

        return min(max(0,cnt1-1),cnt0);
    }
};
