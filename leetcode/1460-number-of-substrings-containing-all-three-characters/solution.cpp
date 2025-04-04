class Solution {
public:
    int give(int n, string &s, int k){
        int l=0,r=0,ans=0;
        vector<int>ch(3,0);

        while(r<n){
            ch[s[r]-'a']++;
            while(ch[0]>0 && ch[1]>0 && ch[2]>0){
                ch[s[l]-'a']--;
                l++;
                ans+=n-r;
            }
            r++;
        }

        return ans;
    }

    int numberOfSubstrings(string s) {
        int n = s.size();
        return give(n,s,3);
    }
};
