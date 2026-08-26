class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int l = 0, r = 0;

        int cnt = 0;
        int idx = -1;
        int sz = 0;

        while(r<n){
            cnt+=(s[r]=='1');

            while(l<=r && cnt>=k){
                if(cnt==k){
                    if(sz==0 || sz>r-l+1){
                        sz = r-l+1;
                        idx = l;
                    }else if(sz==r-l+1){
                        int i = idx,j = l;

                        while(i<=idx+sz-1 && j<=r && s[i]==s[j]){
                            i++;
                            j++;
                        }
                        if(i<=idx+sz-1 && j<=r && s[i]>s[j]){
                            idx = l;
                        }
                    }
                }
                cnt-=(s[l]=='1');
                l++;
            }

            r++;
        }
        
        if(sz==0) return "";
        return s.substr(idx,sz);
    }
};
