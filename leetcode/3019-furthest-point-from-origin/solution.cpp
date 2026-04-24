class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int neut = 0, left = 0, right = 0;

        for(auto &ele:moves){
            if(ele=='_') neut++;
            else if(ele=='L') left++;
            else right++;
        }

        return max(left,right)-min(left,right)+neut;
    }
};
