/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";

        if(!root) return "";

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();

            for(int i=0;i<sz;i++){
                TreeNode* t = q.front();
                q.pop();

                if(!t){
                    s+='#';
                }else{
                    s+=to_string(t->val);
                    q.push(t->left);
                    q.push(t->right);
                }

                s+=',';
            }
        }
        s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.

    pair<string,int> inc(string &s, int itr){
        int n = s.size();
        string t = "";
        while(itr<n && s[itr]!=','){
            t+=s[itr];
            itr++;
        }
        return {t,itr+1};
    }

    TreeNode* deserialize(string s) {
        int n = s.size();
        if(n==0) return nullptr;

        int itr = 0;
        queue<TreeNode*>q;

        auto [t,it] = inc(s,itr);
        TreeNode* root = new TreeNode(stoi(t));

        q.push(root);
        itr = it;


        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            // left child
            auto [leftStr,leftItr] = inc(s,itr);
            TreeNode* left = leftStr!="#"?new TreeNode(stoi(leftStr)):nullptr;
            if(left) q.push(left);
            itr = leftItr;

            // rightChild
            auto [rightStr,rightItr] = inc(s,itr);
            TreeNode* right = rightStr!="#"?new TreeNode(stoi(rightStr)):nullptr;
            if(right) q.push(right);
            itr = rightItr;
            
            curr->left = left;
            curr->right = right;
        }

        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
