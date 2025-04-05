class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(),m = t.size();
        int l=0,r=0,mnl=0,mnr=-1,mnsz=INT_MAX;

        vector<int>v(256,0);
        int cnt=0;

        for(auto ele:t){
            v[ele]++;
        }

        while(r<n){
            if(v[s[r]]>0) cnt++;
            v[s[r]]--;
            while(cnt==m){
                if(mnsz>r-l+1){
                    mnsz = r-l+1;
                    mnl=l;
                    mnr=r;
                }
                v[s[l]]++;
                if(v[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }

        return s.substr(mnl,mnr-mnl+1);
    }
};
