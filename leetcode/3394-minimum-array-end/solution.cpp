class Solution {
    #define ll long long
public:
    long long minEnd(int n, int x) {
        string s = bitset<64>(x).to_string();
        string k = bitset<64>(n-1).to_string();
        ll slen = s.size()-1;
        ll klen = k.size()-1;

        while(slen>=0 && klen>=0){
            if(s[slen]=='0'){
                s[slen] = k[klen];
                klen--;
            }
            slen--;
        }
        string ans = k.substr(0,max(klen,0LL))+s;
        return stoll(ans,nullptr,2);
    }
};
