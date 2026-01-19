class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        bool digit = false;
        bool sign = true;

        long long num = 0;
        long long place = 1;

        for(int i=0;i<n;i++){
            if(!isdigit(s[i])){
                if(digit) break;
                else if(s[i]=='+' || s[i]=='-'){
                    sign = s[i]=='+';
                    digit = true;
                }else if(s[i]==' ') continue;
                else break;
            }else{
                digit=true;
                num*=10;

                num+=s[i]-'0';

            }

            if(num>=1e11) break;
        }

        num = sign?num:-num;

        if(num>(1LL<<31)-1){
            num = (1LL<<31)-1;
        }
        if(num<-(1LL<<31)){
            num = (1LL<<31);
        }

        return num;

    }
};
