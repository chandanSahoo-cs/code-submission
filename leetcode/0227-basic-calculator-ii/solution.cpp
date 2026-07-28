class Solution {
public:
    int calculate(string s) {
        int n = s.size();

        int i = 0;
        int ans = 0;
        int prev = 0;

        while(i<n){
            if((s[i]>='0' && s[i]<='9') || s[i]==' '){
                if(s[i]!=' '){
                    ans*=10;
                    ans+=(s[i]-'0');
                    prev = ans;
                }
                i++;
            }else{
                char op = s[i];
                i++;

                int b = 0;
                while(i<n && ((s[i]>='0' && s[i]<='9') || s[i]==' ')){
                    if(s[i]!=' '){
                        b*=10;
                        b+=(s[i]-'0');
                    }
                    i++;
                }
                if(op=='+'){
                    ans+=b;
                    prev = b;
                }else if (op=='-'){
                    ans-=b;
                    prev = -b;
                }else if(op=='*'){
                    ans-=prev;
                    ans = ans+prev*b;
                    prev = prev*b;
                }else{
                    ans-=prev;
                    ans = ans+prev/b;
                    prev = prev/b;
                }
            }
        }

        return ans;
    }
};
