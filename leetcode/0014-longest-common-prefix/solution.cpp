class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());

        string s1 = strs[0];
        string s2 = strs.back();

        int i=0,j=0;

        while(i<s1.size() && j<s2.size()){
            if(s1[i]!=s2[j]) break;
            i++;
            j++;
        }

        return s1.substr(0,i);
    }
};
