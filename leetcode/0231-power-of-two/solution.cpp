class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long p = n;
        if(!p) return 0;
        return !(p & p-1);
    }
};
