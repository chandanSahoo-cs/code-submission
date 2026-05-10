class Solution {
public:

    bool check(char c){
        return c>='a' && c<='z';
    }

    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";

        for(auto &ele:chunks){
            s+=ele;
        }
        s+="#";

        int n = s.size();

        unordered_map<string,int>mp;
        string word = "";

        for(int i=0;i<n;i++){
            
            char c = s[i];

            bool isAlpha = (c>='a' && c<='z');
            bool isHyphen = false;

            if(i>0 && i<n-1 && c=='-'){
                isHyphen = (s[i-1]>='a' && s[i-1]<='z') && (s[i+1]>='a' && s[i+1]<='z');  
            }

            if(isAlpha || isHyphen){
                word+=c;
            }else{
                if(word.size()>0){
                    mp[word]++;
                    word = "";
                }
            }
        }

        int q = queries.size();
        vector<int>ans(q);

        for(int i=0;i<q;i++){
            ans[i] = mp[queries[i]];
        }

        return ans;
    }
};
