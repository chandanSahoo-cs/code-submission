class Solution {
public:
    
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int val = 1;

        if(n<=2) return n;

        while(n){
            n>>=1;
            val<<=1;
        }

        return val;
    }
};
