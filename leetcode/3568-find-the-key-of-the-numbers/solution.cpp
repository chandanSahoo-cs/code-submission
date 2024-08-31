class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int num=0;
        num+=1000*(min({num1/1000,num2/1000,num3/1000}));
        num1%=1000,num2%=1000,num3%=1000;
        
        num+=100*(min({num1/100,num2/100,num3/100}));
        num1%=100,num2%=100,num3%=100;
        
        num+=10*(min({num1/10,num2/10,num3/10}));
        num1%=10,num2%=10,num3%=10;
        
        num+=1*(min({num1,num2,num3}));
        return num;
        
    }
};
