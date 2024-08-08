class Solution {
public:
    bool check(string &s,int n){
        int size=s.size();
        if(n>=size/2) return true;
        if(s[n]!=s[size-1-n]) return false;
        return check(s,n+1);
    }
    bool isPalindrome(string s) {
        string og="";
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i]) || isdigit(s[i])) og+=tolower(s[i]);
        }
        return check(og,0);
    }
};
