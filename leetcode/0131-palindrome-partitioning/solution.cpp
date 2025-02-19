class Solution {
public:
    vector<vector<string>>ans;

    bool isPalindrome(string s){
        int n = s.size();
        int l=0,r=n-1;

        while(l<r){
            if(s[l++]!=s[r--]) return false;
        }

        return true;
    }

    void fill(string &s, vector<string> &c, string store, int i){
        if(s.size()==i){
            if(isPalindrome(store) && !store.empty()){
                c.push_back(store);
                ans.push_back(c);
                c.pop_back();
            }
            return;
        }

        if(isPalindrome(store)){
            if(!store.empty()){
                c.push_back(store);
                fill(s,c,string(1,s[i]),i+1);
                c.pop_back();
            }
        }

        fill(s,c,store+s[i],i+1);

        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> c;
        string store ="";

        fill(s,c,store,0);
        return ans;
    }
};
