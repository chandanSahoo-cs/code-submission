class Solution {
public:
    int minimumPushes(string word) {
        unordered_set<char>st(word.begin(),word.end());

        int n = st.size();

        int all = n/8;
        int some = n%8;

        int ans = 0;

        for(int i=1;i<=all;i++){
            ans += i*8;
        }

        ans+=some*(all+1);

        return ans;
    }
};
