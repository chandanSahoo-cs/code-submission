class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int mx = 0;

        for(int i=0;i<32;i++){
            if((n>>i)==0) break;
            if((n>>i)&1){
                if(prev!=-1){
                    mx = max(mx,i-prev);
                }
                prev = i;
            }
        }

        return mx;
    }
};
