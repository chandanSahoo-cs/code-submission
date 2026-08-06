class Solution {
public:
    int calc(int n){
        int ans = 1;
        while(n){
            ans*=(n%10);
            n/=10;
        }

        return ans;
    }
    int smallestNumber(int n, int t) {
        int i = n;

        while(true){
            if(calc(i)%t==0) return i;
            i++;
        }

        return -1;
    }
};
