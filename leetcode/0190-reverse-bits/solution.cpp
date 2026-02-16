class Solution {
public:
    int reverseBits(int n) {
        string s = "";

        for(int i=0;i<=31;i++){
            s+=((n>>i)&1)+'0';
        }

        int ans = 0;
        long long p = 1;
        for(int d = s.size()-1;d>=0;d--){
            if(s[d]=='1'){
                ans+=p;
            }
            p*=2;
        }

        return ans;
    }
};
