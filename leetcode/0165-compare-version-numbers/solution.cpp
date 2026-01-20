class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.size(), m = v2.size();

        int i = 0, j = 0;

        while(i<n || j<m){

            int c1 = 0, c2 = 0;

            while(i<n && v1[i]!='.'){
                c1*=10;
                c1+=(v1[i]-'0');
                i++;
            }

            while(j<m && v2[j]!='.'){
                c2*=10;
                c2+=(v2[j]-'0');
                j++;
            }

            if(c1>c2) return 1;
            if(c1<c2) return -1;

            while(i<n && v1[i]=='.') i++;
            while(j<m && v2[j]=='.') j++;
        }

        return 0;
    }
};
