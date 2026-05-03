class Solution {
public:
    int rot(int n){
        int ans = 0;

        while(n){
            ans*=10;
            ans+=n%10;
            n/=10;
        }

        return ans;
    }
    
    int sumOfPrimesInRange(int n) {
        int r = rot(n);

        int sum = 0;
        
        for(int i=min(n,r);i<=max(n,r);i++){
            bool flag = (i!=1);
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    flag=false;
                    break;
                }
            }

            if(flag){
                sum+=i;
            }
        }

        return sum;
    }
};
