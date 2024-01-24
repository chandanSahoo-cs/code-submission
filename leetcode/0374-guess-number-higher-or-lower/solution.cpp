/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
#define ll long long
public:
    int guessNumber(int n) {
        ll s=1;
        ll e=n;
        ll mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(guess(mid)==-1) e=mid-1;
            else if(guess(mid)==1) s=mid+1;
            else break;
        }
        return mid;
    }
};
