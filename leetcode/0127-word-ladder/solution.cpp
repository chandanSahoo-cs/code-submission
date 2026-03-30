class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        
        unordered_set<string>st(wordList.begin(),wordList.end());
        unordered_set<string>vis;

        queue<string>q;
        
        q.push(beginWord);
        vis.insert(beginWord);

        int level = 1;

        while(!q.empty()){
            int sz = q.size();
            level++;

            for(int k=0;k<sz;k++){
                string u = q.front();
                q.pop();

                for(int i=0;i<u.size();i++){
                    char curr = u[i];

                    for(char c='a';c<='z';c++){
                        u[i]=c;
                        if(st.count(u) && !vis.count(u)){
                            if(u==endWord) return level;
                            q.push(u);
                            vis.insert(u);
                        }
                    }
                    u[i]=curr;
                } 
            }
        }

        return 0;
    }
};
