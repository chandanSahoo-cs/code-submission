/* Not at my current level*/
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size(), m = queryCharacters.size();
        set<int>lens,bounds;

        vector<int>lengths(n+1);

        auto addLen = [&](int len){
            if(++lengths[len]==1){
                lens.insert(len);
            }
        };

        auto remLen = [&](int len){
            if(--lengths[len]==0){
                lens.erase(len);
            }
        };

        bounds.insert(0);
        bounds.insert(n);

        int prev=0;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                bounds.insert(i);
                addLen(i-prev);
                prev = i;
            }
        }
        addLen(n-prev);

        auto update = [&](int idx, bool merge){

            if(merge){
                auto it = bounds.find(idx);
                int right = *std::next(it);
                int left = *std::prev(it);

                remLen(right-idx);
                remLen(idx-left);
                addLen(right-left);
                bounds.erase(it);
            }else{
                auto it = bounds.lower_bound(idx);
                int right = *it;
                int left = *std::prev(it);

                remLen(right-left);
                addLen(idx-left);
                addLen(right-idx);
                bounds.insert(idx);
            }
        };

        vector<int>ans(m);

        for(int i=0;i<m;i++){
            int idx = queryIndices[i];
            int chr = queryCharacters[i];

            if(idx>0){
                bool old = s[idx-1]!=s[idx];
                bool curr = s[idx-1]!=chr;

                if(old!=curr){
                    update(idx,!curr);
                }
            }

            if(idx+1<n){
                bool old = s[idx]!=s[idx+1];
                bool curr = chr!=s[idx+1];

                if(old!=curr){
                    update(idx+1,!curr);
                }
            }

            s[idx] = chr;

            ans[i] = *lens.rbegin();
        }

        return ans;
    }
};
