const int mod = 1e9+7;
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int g1 = 0, g2 = 0;
        int cnt = 0;

        for(auto ele:nums){
            if(ele<a) cnt = ((cnt+g1)%mod+g2)%mod;
            else if(ele>=a && ele<=b){
                cnt = (cnt+g2)%mod;
                g1++;
            }else{
                g2++;
            }
        }

        return cnt;
    }
};
