class Solution {
public:
    int calc(int n){
        int sum = 0;

        while(n){
            sum+=n%10;
            n/=10;
        }

        return sum;
    }

    int largestInteger(int n, int s) {
        int limit = 1;

        while(n){
            limit*=10;
            n--;
        }

        for(int i=limit-1;i>=0;i--){
            if(calc(i)==s) return i;
        }

        return -1;
    }
};
