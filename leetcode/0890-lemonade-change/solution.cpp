class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cntFive = 0, cntTen = 0;

        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) cntFive++;
            else if(bills[i]==10) {
                cntTen++;
                if(cntFive>0) cntFive--;
                else return false;
            }else {
                if( cntFive>=1 && cntTen>=1){
                    cntFive--;
                    cntTen--;
                }else if(cntFive>=3){
                    cntFive-=3;
                }else return false;
            }

        }

        return true;
    }
};
