#define ll long long

class Solution {
public:

    ll sumAndMultiply(int n) {
        int sum = 0;
        int num = 0;

        string s = to_string(n);

        for(int i=0;i<s.size();i++){
            int val = s[i]-'0';
            if(val!=0){
                sum+=val;
                num*=10;
                num+=val;
            }
        }   

        return num*1LL*sum;
    }
};
