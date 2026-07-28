class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int>alpha(26);

        for(auto c:s){
            alpha[c-'a']++;
        }

        string t(n,'#');
        int l = 0, r = n-1;

        for(int i=0;i<26;i++){
            if(alpha[i]&1){
                t[n/2] = 'a'+i;
                alpha[i]--;
            }

            while(alpha[i]){
                t[l] = 'a'+i;
                t[r] = 'a'+i;
                alpha[i]-=2;
                l++;
                r--;
            }
        }

        return t;
    }
};
