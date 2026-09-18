class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int>lst(26,-1);
        vector<int>frst(26,-1);

        vector<bool>isValid(26,true);

        for(int i=0;i<n;i++){
            lst[s[i]-'a'] = i;
            frst[s[n-i-1]-'a'] = n-i-1;
        }

        for(int i=0;i<26;i++){
            if(frst[i]!=-1){
                for(int j=frst[i];j<=lst[i];j++){
                    if(frst[s[j]-'a']<frst[i]){
                        isValid[i] = false;
                        break;
                    }
                    lst[i] = max(lst[s[j]-'a'],lst[i]);
                }
            }
        }

        vector<string>ans;
        int prev = n+1;

        for(int i=n-1;i>=0;i--){
            int idx = s[i]-'a';
            if(isValid[idx] && i==frst[idx] && prev>lst[idx]){
                ans.push_back(s.substr(i,lst[idx]-i+1));
                prev = i;
            }
        }

        return ans;
    }
};
