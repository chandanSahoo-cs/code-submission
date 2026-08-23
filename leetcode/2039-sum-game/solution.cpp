class Solution {
public:
    /*
        let q = number of ?
        if q is odd
            if every q lies on either side
                Alice wins
            if first half has odd q and secnd half has even q or vice versa
                Alice wins
        if q is even
            if q is equally divide on both side 
                if sum is equal for both halves
                    Bob wins
                else 
                    Alice wins
            if q is not divided equally 
                if sum is equal for both halves
                    Alice wins
                else
                    if the side having smaller sum has fewer q's
                        Alice Wins
                    else
                        if biggerSum-smallerSum == ((qOnSmaller-qOnHigher)/2)*9
                            Bob Wins
                        else Alice wins

        the two cases where bob wins
        - when sum is equal for both halves and q is equal on both side
        - q is not equally divided and  if biggerSum-smallerSum == ((qOnSmaller-qOnHigher)/2)*9

        first one is special case of second when delta(q) = 0 and delta(sum)=0

    */

    bool sumGame(string nums) {
        int n = nums.size();

        auto compute = [&](int l, int r)->pair<int,int>{
            int sum = 0, q = 0;
            for(int i=l;i<r;i++){
                if(nums[i]!='?') sum+=nums[i]-'0';
                else q++;
            }

            return {sum,q};
        };

        auto [sum1,q1] = compute(0,n/2);    
        auto [sum2,q2] = compute(n/2,n);

        if((q1+q2)&1) return true;
        if(sum1<sum2 && q1<q2) return true;
        if(sum2<sum1 && q2<q1) return true;

        if(abs(sum1-sum2)==(abs(q1-q2)/2)*9) return false;

        return true;
    }
};
