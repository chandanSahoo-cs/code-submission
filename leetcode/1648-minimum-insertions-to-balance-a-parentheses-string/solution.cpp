class Solution {
public:
    int minInsertions(string s) {
       int n = s.size();

       int cnt = 0;

       int i = 0;
       int ans = 0;
    
       while(i<n){
        if(s[i]=='(') cnt++;
        else if(s[i]==')'){
            if(cnt>0) cnt--;
            else ans++;

            if(i==n-1 || s[i+1]!=')'){
                ans++;
            }else i++; 
        }
        i++;
       }

       return ans+cnt*2;
    }
};
