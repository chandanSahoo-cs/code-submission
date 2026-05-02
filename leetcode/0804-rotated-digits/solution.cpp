class Solution {
public:
    int check(int d){
        if(d==0 || d==1 || d==8) return d;
        else if(d==2) return 5;
        else if(d==5) return 2;
        else if(d==6) return 9;
        else if(d==9) return 6;

        return -1;
    }

    bool compute(int n){
        int tn = n;
        int mul = 1;
        int curr = 0;

        while(tn){
            int d = check(tn%10);
            if(d==-1) return false;
            curr+=d*mul;
            mul*=10;
            tn/=10;
        }

        if(curr==n) return false;
        return true;
    }

    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i=1;i<=n;i++){
            cnt+=compute(i);
        }

        return cnt;
    }
};
