class Solution {
public:
    void reverse(vector<char>&s,int n){
        if(n>=s.size()/2) return;
        char temp=s[n];
        s[n]=s[s.size()-1-n];
        s[s.size()-1-n]=temp;
        reverse(s,++n);
    }
    void reverseString(vector<char>& s) {
        reverse(s,0);
    }
};
