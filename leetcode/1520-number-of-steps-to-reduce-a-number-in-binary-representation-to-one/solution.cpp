class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        
        int cnt = 0;
        int carry = 0;

        for(int i=n-1;i>=0;i--){
            if((s[i]=='1' && carry==0) || (s[i]=='0' && carry==1)){
                if(i!=0){
                    cnt+=2;
                    carry=1;
                }
            }else if(s[i]=='1' && carry==1){
                cnt+=1;
                carry=1;
            }else {
                cnt+=1;
                carry=0;
            }
        }

        return cnt;
    }
};

/*
- if (s[i]==1 && carry==0) || (s[i]==0 && carry==1)
    if(i!=n-1){
        cnt+=2;
        carry=1;
    }
- if s[i]==1 && carry==1
    cnt+=1;
    carry=1;
- if s[i]==0 && carry==0
    cnt+=1;
    carry=0;
*/
