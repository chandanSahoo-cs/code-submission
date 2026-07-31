class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26);

        for(auto c:word){
            freq[c-'a']++;
        }

        vector<int>foo(26);
        iota(foo.begin(),foo.end(),0);

        sort(foo.begin(),foo.end(),[&](int i, int j){
            return freq[i]>freq[j];
        });

        int itr = 1;
        int limit = 0;
        int ans = 0;

        for(int i=0;i<26;i++){
            ans+=freq[foo[i]]*itr;
            limit++;
            if(limit==8){
                limit = 0;
                itr++;
            }
        }

        return ans;
    }
};
