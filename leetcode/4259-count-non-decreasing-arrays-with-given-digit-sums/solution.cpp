const int limit = 5000;
const int mod = 1e9+7;

class Solution {
public:

    int calc(int i){

        int sum = 0;

        while(i){
            sum+=(i%10);
            i/=10;
        }

        return sum;
    }

    int countArrays(vector<int>& digitSum) {
        int n = digitSum.size();

        vector<int>sum(5001);

        for(int i=0;i<5001;i++){
            sum[i] = calc(i);
        }

        vector<int>next(5002,1);
        vector<int>curr(5002,1);
        next[5001]=curr[5001]=0;

        for(int i=n-1;i>=0;i--){
            for(int j=5000;j>=0;j--){
                
                int ans = 0;
                if(digitSum[i]==sum[j]){
                    ans=(ans+next[j])%mod;
                }

                ans=(ans+curr[j+1])%mod;

                curr[j]=ans;
            }

            next = curr;
        }

        return next[0];
    }
};


/*
0<=arr[i]<=5000
1<=digits.len<=1000
0<=digitSum[i]<=50
*/
