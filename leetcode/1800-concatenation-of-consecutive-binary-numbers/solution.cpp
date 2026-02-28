#define ll long long
const int mod = 1e9+7;

class Solution {
public:

    int concatenatedBinary(int n) {
        ll num = 0;
        int bits = 0;
        for(int i=1;i<=n;i++){

            if((i&(i-1))==0) bits++;

            num<<=bits;
            num = num | i;
            num%=mod;
        }

        return num;
    }
};

/*
1 10 11 100 101 110 111 1000 1001 1010 1011 1100
*/

