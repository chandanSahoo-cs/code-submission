class Solution {
public:
    int compute(string &s, int k){
        int n = s.size();
        int l = 0, r = 0;

        vector<int>alpha(3);

        int cnt = 0;
        
        while(r<n){
            alpha[s[r]-'a']++;

            while((alpha[0]>0)+(alpha[1]>0)+(alpha[2]>0)>k){
                alpha[s[l]-'a']--;
                l++;
            }
            
            cnt+=r-l+1;

            r++;
        }

        return cnt;
    }

    int numberOfSubstrings(string s) {
        int n = s.size();
        return (n*1LL*(n+1))/2-compute(s,2);
    }
};
