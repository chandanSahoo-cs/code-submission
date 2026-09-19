class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int x = clamp(xc,x1,x2)-xc;
        int y = clamp(yc,y1,y2)-yc;

        return x*x+y*y<=r*r;
    }
};

/*
Clamp means forcing a number to stay inside a range [low, high]:

below low → you get low
above high → you get high
already inside → you get the number unchanged
*/
