class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string cmp = strs[0];

        for(int i=1;i<n;i++){
            int l=0;
            while(l<cmp.size() && l<strs[i].size() && cmp[l]==strs[i][l]) l++;

            cmp.resize(l);

            if(cmp.size()==0) break;
        }

        return cmp;
    }
};
