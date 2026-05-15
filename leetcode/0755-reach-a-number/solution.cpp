class Solution {
public:
    int reachNumber(int target) {
        int i = 0;
        int sum = 0;

        target = abs(target);

        while(sum<target){
            sum+=i;
            i++;
        }

        int delta = target-sum;

        return delta%2==0?i-1:i+(i%2?0:1);
    }
};
