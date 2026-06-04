class Solution {
public:
    int calc(int num){

        vector<int>dig;

        while(num){
            dig.push_back(num%10);
            num/=10;
        }

        if(dig.size()<3){
            return 0;
        }

        int cnt = 0;

        for(int i=1;i<dig.size()-1;i++){
            if(dig[i-1]<dig[i] && dig[i+1]<dig[i]) cnt++;
            if(dig[i-1]>dig[i] && dig[i+1]>dig[i]) cnt++;
        }

        return cnt;
    }
    
    int totalWaviness(int num1, int num2) {
        int sum = 0;
        for(int i=num1;i<=num2;i++){
            sum+=calc(i);
        }

        return sum;
    }
};
