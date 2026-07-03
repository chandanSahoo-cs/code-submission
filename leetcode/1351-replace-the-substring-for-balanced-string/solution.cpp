class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char,int>mp;

        mp['Q']=0;
        mp['W']=0;
        mp['E']=0;
        mp['R']=0;

        for(auto c:s){
            mp[c]++;
        }

        int l = 0, r = 0;

        int mn = INT_MAX;

        if(mp['Q']==n/4 && mp['W']==n/4 && mp['E']==n/4 && mp['R']==n/4) return 0;

        while(r<n){
            mp[s[r]]--;

            bool flag = true;

            while(mp['Q']<=n/4 && mp['W']<=n/4 && mp['E']<=n/4 && mp['R']<=n/4){
                mn = min(mn,r-l+1);
                mp[s[l]]++;
                if(l==r) break;
                l++;
            }
            r++;
        }

        return mn;
    }
};
