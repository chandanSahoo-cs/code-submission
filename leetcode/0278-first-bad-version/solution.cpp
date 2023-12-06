// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==0 or n==1) return n;
        int start=1, end=n, mid=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(!isBadVersion(mid))start=mid+1;
            else if(isBadVersion(mid))end=mid-1;
        }
        return start;
    }
};
