class Solution {
public:
    int divisors(int num){

        int cnt=0;
        int sum=0;
        for(int i=1;i*i<=num;i++){
            if(num%i==0){
                sum+=i;
                cnt++;

                if(i!=num/i){
                    sum+=num/i;
                    cnt++;
                }
            }

            if(cnt>4) return 0;
        }

        if(cnt<4) return 0;
        return sum;

    }

    int sumFourDivisors(vector<int>& nums) {

        int ans = 0;

        for(auto ele:nums){
            ans+=divisors(ele);
        }

        return ans;
    }
};
