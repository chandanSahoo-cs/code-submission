class Solution {
public:
    bool isPerfectSquare(int num) {
        long long start=1,end=num,mid=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(mid*mid>num) end=mid-1;
            else if(mid*mid<num) start=mid+1;
            else return true;
        }
        return false;
    }
};
