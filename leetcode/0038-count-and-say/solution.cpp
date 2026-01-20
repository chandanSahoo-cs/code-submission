class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while(--n){
            string t =  "";
            int cnt=1;
            for(int i=1;i<s.size();i++){
                if(s[i]!=s[i-1]){
                    t+=to_string(cnt);
                    t+=s[i-1];
                    cnt=1;
                }else cnt++;
            }

            t+=to_string(cnt);
            t+=s.back();

            s=t;
        }

        return s; 
    }
};
