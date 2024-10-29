#define ll long long

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ll n = strs.size();
        string cmp = strs[0];
        string temp = "";
        for(ll i=1;i<n;i++){
            if(!strs[i].size()) return "";
            ll m = min(strs[i].size(),cmp.size());
            for(ll j=0;j<m;j++){
                if(strs[i][j]==cmp[j]){
                    temp+=cmp[j];
                }
                else{
                    cmp = temp;
                    temp = "";
                    break;
                }
                if(j==m-1){
                    cmp = temp;
                    temp = "";
                }
            }
        }

        return cmp;
    }
};
