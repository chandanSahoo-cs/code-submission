class Solution {
public:
    string compute(int num){
        string s = "";
        for(int i=7;i>=0;i--){
            if(num&(1<<i)){
                s+='1';
            }else s+='0';
        }

        return s;
    }

    bool isPalin(string t){
        int l = 0, r = t.size()-1;

        while(l<r){
            if(t[l]!=t[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    bool isPalindromic(string s) {
        string t = "";

        for(auto ele:s){
            
            t+=compute(ele);
        }

        return isPalin(t);    
    }
};
