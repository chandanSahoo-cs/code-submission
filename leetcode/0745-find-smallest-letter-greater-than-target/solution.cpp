class Solution {
    #define ll long long
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        ll s=0,e=letters.size()-1; bool flag=false;
        while(s<=e){
            ll m=s+(e-s)/2;
            if(letters[m]>target) {
                flag=true;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        if(flag) return letters[s];
        else return letters[0];
    }
};
