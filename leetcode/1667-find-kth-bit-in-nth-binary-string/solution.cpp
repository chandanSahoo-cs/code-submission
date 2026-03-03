class Solution {
public:
    char bit(int k){
        int tn = log2(k)+1;
        if(tn==1) return '0';

        int len = (1<<tn)-1;

        int mid = (len+1)/2;

        if(k==mid) return '1';

        if(k>mid){
            char b = bit(len-k+1);
            
            return b=='0'?'1':'0';
        }

        return bit(k);
    }

    char findKthBit(int n, int k) {
        return bit(k);
    }
};

/*
0111001101 1 0001
- 15-11 = 4

0111 0 01
- 7-5+1=3

01 1
- 3-3+1 = 1
*/


