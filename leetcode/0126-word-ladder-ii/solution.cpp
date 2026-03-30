class Solution {
public:
    vector<vector<string>>ans;
    void dfs(unordered_map<string,int>&vis, vector<string>&part, string &u, string &tr ){
        // string u = part.back();
        if(u==tr){
            vector<string>res;
            for(int i=part.size()-1;i>=0;i--){
                res.push_back(part[i]);
            }
            ans.push_back(res);
            return;
        }

        string temp = u;
        for(int i=0;i<u.size();i++){
            char curr = temp[i];
            for(char c='a';c<='z';c++){
                temp[i]=c;
                if(vis.count(temp) && vis[temp]+1==vis[u]){
                    part.push_back(temp);
                    dfs(vis,part,temp,tr);
                    part.pop_back();
                }
            }
            temp[i]=curr;
        }

        return;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st(wordList.begin(),wordList.end());
        unordered_map<string,int>vis;

        queue<string>q;

        q.push(beginWord);
        vis[beginWord]=1;

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
                            q.push(u);
                            vis[u]=level;

                            if(u==endWord){
                                vector<string>part = {endWord};

                                dfs(vis,part,endWord,beginWord);

                                return ans;
                            }

                        }
                    }
                    u[i]=curr;
                } 
            }
        }

        return {};
    }
};
