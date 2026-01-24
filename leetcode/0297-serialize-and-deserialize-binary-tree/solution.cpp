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
        if(root==nullptr) return "";
        string s = "";

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp==nullptr){
                s+='#';
            }else{
                s+=to_string(temp->val);
                q.push(temp->left);
                q.push(temp->right);
            }
            s+='|';

        }


        return s;
    }

    TreeNode* giveNum(string &s, int &ind){
        int strt = ind;

        while(ind<s.size() && s[ind]!='|'){
            ind++;
        }
        ind++;

        if(ind-strt-1==1 && s[strt]=='#') return nullptr;

        bool sign = true;
        int val = 0;

        while(strt<ind-1){
            if(s[strt]=='-') sign = false;
            else{
                val*=10;
                val+=s[strt]-'0';
            }
            strt++;
        }

        val = sign?val:-val;

        TreeNode* root = new TreeNode(val);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;

        int ind=0;

        TreeNode* root = giveNum(data,ind);

        queue<TreeNode*>q;
        q.push(root);

        while(ind<data.size()){
            int sz = q.size();

            for(int i=0;i<sz;i++){
                TreeNode* curr = q.front();
                q.pop();

                curr->left = giveNum(data,ind);
                curr->right = giveNum(data,ind);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
