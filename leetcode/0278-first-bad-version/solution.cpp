// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=1,e=n,store;
        while(s<=e){
            int m=s+(e-s)/2;
            if(isBadVersion(m)){
                store=m;
                e=m-1;
            }
            else if(!isBadVersion(m)) s=m+1;
        }
        return store;
    }
};
