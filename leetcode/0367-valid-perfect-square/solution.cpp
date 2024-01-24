class Solution {
    #define ll long
public:
    bool isPerfectSquare(int num) {
        ll s=0, e=num; bool flag=false;
        while(s<=e){
            ll m=s+(e-s)/2;
            if(m*m==num){
                flag=true;
                break;
            }
            else if (m*m>num) e=m-1;
            else s=m+1;
        }
        return flag;
    }
};
