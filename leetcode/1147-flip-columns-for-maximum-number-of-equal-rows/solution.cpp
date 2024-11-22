class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<string,int>mp;
        vector<string>st;
        for(int i=0;i<m;i++){
            string s1 = "";
            string s2 = "";
            for(int j=0;j<n;j++){
                s1+=char('0'+mat[i][j]);
                s2+=char('0'+(mat[i][j]^1));
            }
            st.push_back(s1);
            mp[s1]++;
            mp[s2]++;
        }
        auto bin = [&](string binary){
            for(auto &ch:binary) ch = (ch=='0')?'1':'0';
            return binary;
        };

        int mx = 0;
        for(int i=0;i<st.size();i++){
            mx = max(mx,((mp[st[i]]+mp[bin(st[i])])>>1));
        }
        return mx;
    }
};
