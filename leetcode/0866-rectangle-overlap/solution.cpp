class Solution {
public:
    bool check(int l1, int r1, int l2, int r2){
        return l1<r2 && l2<r1;
    }
    bool isRectangleOverlap(vector<int>& a, vector<int>& b) {
        return check(a[0],a[2],b[0],b[2]) &&
        check(a[1],a[3],b[1],b[3]);
    }
};
