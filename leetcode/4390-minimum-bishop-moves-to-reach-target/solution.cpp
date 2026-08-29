class Solution {
public:
    
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];

        if(((sr+sc)&1) != ((tr+tc)&1)) return -1;
        if(sr==tr && sc==tc) return 0;

        /*
            diag1 : r+c
            diag2 : r-c
        */

        if(sr+sc==tr+tc || sr-sc==tr-tc) return 1;
        return 2;
    }
};
