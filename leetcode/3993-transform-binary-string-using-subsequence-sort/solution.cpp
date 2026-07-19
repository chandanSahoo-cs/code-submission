class Solution {
public:

    int cntZ(string &s){
        int cnt = 0;
        for(auto c:s){
            cnt+=(c=='0');
        }

        return cnt;
    }

    bool check(string &s, int org0, string &t){
        int n = s.size();

        int cnt0 = cntZ(t);
        int wild = 0;

        for(auto ele:t){
            wild+=(ele=='?');
        }

        if(cnt0>org0 || cnt0+wild<org0) return false;

        for(int i=0;i<n;i++){
            if(t[i]=='?'){
                if(cnt0==org0){
                    t[i]='1';
                }else{
                    t[i]='0';
                    cnt0++;
                }
            }
        }

        int zt = 0, zs = 0;

        for(int i=n-1;i>=0;i--){
            zt+=(t[i]=='1');
            zs+=(s[i]=='1');

            if(zt<zs) return false;
        }

        return true;
    }

    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<bool>ans;
        int org0 = cntZ(s);

        for(auto &ele:strs){
            ans.push_back(check(s,org0,ele));
        }    

        return ans;
    }
};
