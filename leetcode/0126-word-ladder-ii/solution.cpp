class Solution {
    vector<vector<string>>ans;
public:
    void dfs(string &word, unordered_map<string,int>&mark, string &beginWord, vector<string>&partAns){

        int bn = word.size();

        if(mark.find(word)==mark.end()) return;

        if(word==beginWord){
            vector<string>part;
            for(int i=partAns.size()-1;i>=0;i--){
                part.push_back(partAns[i]);
            }
            ans.push_back(part);
            return;
        }

        for(int i=0;i<bn;i++){
            string temp = word;
            for(char c='a';c<='z';c++){
                temp[i] = c;
                if(mark.find(temp)!=mark.end() && mark[temp]+1==mark[word]){
                    partAns.push_back(temp);
                    dfs(temp,mark,beginWord,partAns);
                    partAns.pop_back();
                }
            }
        }

        return ;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int bn = beginWord.size();
        unordered_map<string,int>mark;
        unordered_set<string>st(wordList.begin(),wordList.end());

        queue<string>q;

        q.push(beginWord);
        mark[beginWord] = 0;

        while(!q.empty()){
            string ele = q.front();
            q.pop();

            for(int i=0;i<bn;i++){
                string temp = ele;
                for(char c='a';c<='z';c++){
                    temp[i]=c;
                    if(st.count(temp) && mark.find(temp)==mark.end()){
                        q.push(temp);
                        mark[temp]=mark[ele]+1;
                    }
                }
            }
        }

        vector<string>partAns = {endWord};

        dfs(endWord,mark,beginWord,partAns);
        return ans;

    }
};
