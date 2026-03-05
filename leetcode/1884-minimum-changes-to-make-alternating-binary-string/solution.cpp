class Solution {
public:
    int cal(string &s,char curr){
        int cnt=0;

        for(auto c:s){
            if(c!=curr) cnt++;
            
            if(curr=='0') curr='1';
            else curr='0';
        }

        return cnt;
    }

    int minOperations(string s) {
        int cnt = cal(s,'0');
        return min(cnt,(int)s.size()-cnt);
    }
};
