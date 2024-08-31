class Solution {
public:
    string stringHash(string s, int k) {
        int cnt=0;
        int val=0;
        string ans="";
        for(auto ele:s){
            val+=ele-'a';
            cnt++;
            if(cnt==k){
                val%=26;
                ans+=char('a'+val);
                val=0;
                cnt=0;
            }
        }
        return ans;
    }
};
