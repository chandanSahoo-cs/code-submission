class Solution {
public:
    int findComplement(int n) {
        if(n==0) return 1;

        int ans = 0;
        int len = log2(n);


        for(int i=len;i>=0;i--){
            ans*=2;
            ans+=!((1<<i)&n);
        }

        return ans;
    }
};
