class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>st(word.begin(),word.end());

        int cnt = 0;

        for(char c='a',C='A';c<='z',C<='Z';c++,C++){
            if(st.count(c) && st.count(C)) cnt++;
        }

        return cnt;
    }
};
