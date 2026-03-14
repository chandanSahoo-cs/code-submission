class Solution {
public:
    void rec(string &s, int i, char skip, vector<string>&store){
        if(i==0){
            store.push_back(s);
            return;
        }

        for(char c='a';c!='d';c++){
            if(c==skip) continue;
            s+=c;
            rec(s,i-1,c,store);
            s.pop_back();
        }

        return;
    }

    string getHappyString(int n, int k) {
        string s = "";
        vector<string>store;
        rec(s,n,'#',store);

        if(store.size()<k) return "";

        return store[k-1];
    }
};
