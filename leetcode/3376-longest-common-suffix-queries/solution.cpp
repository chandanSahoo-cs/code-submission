class Solution {
public:
    struct TrieNode{
        int idx;
        TrieNode* children[26];

        TrieNode(int i){
            idx = i;
            
            for(int j=0;j<26;j++){
                children[j] = nullptr;
            }
        }

        ~TrieNode(){
            for(int j=0;j<26;j++){
                delete children[j];
            }
        }
    };

    TrieNode* getNode( int i){
        return new TrieNode(i);
    }

    void insertTrie(TrieNode* root, int i, vector<string>& wordsContainer){
        string str = wordsContainer[i];
        int n = str.size();

        for(int j=n-1;j>=0;j--){
            char ch = str[j];
            int chIdx = ch-'a';

            if(root->children[chIdx]==nullptr){
                root->children[chIdx]=getNode(i);
            }

            root = root->children[chIdx];

            if(wordsContainer[root->idx].size()>n){
                root->idx = i;
            }
        }
    }

    int searchTrie(TrieNode* root, string &str){
        int result = root->idx;
        int n = str.size();

        for(int i=n-1;i>=0;i--){
            int chIdx = str[i]-'a';

            root = root->children[chIdx];

            if(root==nullptr) break;

            result = root->idx;
        }

        return result;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        int m = wordsQuery.size();

        vector<int>res(m);

        TrieNode* root = getNode(0);

        for(int i=0;i<n;i++){
            int idx = root->idx;
            if(wordsContainer[idx].size()>wordsContainer[i].size()){
                root->idx = i;
            }
            insertTrie(root,i,wordsContainer);
        }

        for(int i=0;i<m;i++){
            res[i] = searchTrie(root,wordsQuery[i]);
        }

        delete root;
        
        return res;

    }
};
