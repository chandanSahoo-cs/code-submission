class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        vector<int>lower(26,-1);
        vector<int>upper(26,-1);

        for(int i=0;i<n;i++){
            char c = word[i];
            if('A'<=c && c<='Z' && upper[c-'A']==-1){
                upper[c-'A']=i;
            }
            else if('a'<=c && c<='z'){
                lower[c-'a']=i;
            }
        }

        int cnt = 0;

        for(char c='a', C='A';c<='z',C<='Z';c++,C++){
            int valc = c-'a';
            int valC = C-'A';

            if(upper[valC]!=-1 && lower[valc]!=-1 && lower[valc]<upper[valC]) cnt++;
        }

        return cnt;
    }
};
