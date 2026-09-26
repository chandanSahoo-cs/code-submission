class Solution {
public:
    
    int minQueenMoves(vector<int>& src, vector<int>& trg) {

        int sx = src[0], sy = src[1];
        int tx = trg[0], ty = trg[1];

        if(sx==tx && sy==ty) return 0;
        
        if(sx==tx) return 1;
        if(sy==ty) return 1;
        if(sx-sy==tx-ty) return 1;
        if(sx+sy==tx+ty) return 1;

        return 2;
    }
};
