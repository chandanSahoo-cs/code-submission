class Solution {
public:
    bool judgeCircle(string moves) {
        int r=0, c=0;

        for(auto ele:moves){
            if(ele=='U') r--;
            else if(ele=='D') r++;
            else if(ele=='L') c--;
            else c++;
        }

        return r==0 && c==0;
    }
};
