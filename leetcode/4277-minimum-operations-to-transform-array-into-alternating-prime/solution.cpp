class Solution {
public:
    int isPrime[100005];

    void sieve(){
        isPrime[1]=1;

        for(int i=2;i<100005;i++){
            if(isPrime[i]) continue;

            for(int j=i*2;j<100005;j+=i){
                isPrime[j]=1;
            }
        }
    }
    
    int minOperations(vector<int>& nums) {
        sieve();
        vector<int>primes;

        for(int i=2;i<100005;i++){
            if(!isPrime[i]){
                primes.push_back(i);
            }
        }

        int cnt = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(i%2==0){
                cnt+=(*lower_bound(primes.begin(),primes.end(),nums[i]))-nums[i];
            }else{
                if(!isPrime[nums[i]]){
                    if(nums[i]==2) cnt+=2;
                    else cnt++;
                }
            }
        }

        return cnt;
    }
};
