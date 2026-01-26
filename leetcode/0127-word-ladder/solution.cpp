class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        unordered_set<string>st(wordList.begin(),wordList.end());
        unordered_map<string,int>mp;

        queue<string>q;
        q.push(beginWord);
        mp[beginWord]=1;

        int level= 1;
        
        while(!q.empty()){
            int sz = q.size();
            level++;
            for(int j=0;j<sz;j++){
                string curr = q.front();
                q.pop();

                int len = curr.size();

                for(int i=0;i<len;i++){
                    string temp = curr;
                    for(char c='a';c<='z';c++){
                        temp[i] = c;
                        if(st.count(temp) && mp.find(temp)==mp.end()){
                            if(temp==endWord) return level;
                            mp[temp]=level;
                            q.push(temp);
                        }
                    }
                }
            }
        }

        return 0;
    }
};
