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

    string traverse(TreeNode* root){
        if(root==nullptr) return "";

        queue<TreeNode*>q;
        q.push(root);
        string s ="";
        while(!q.empty()){
            vector<TreeNode*>temp;

            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }

            for(auto ele:temp){
                if(ele==nullptr){
                    s.push_back('#');
                }else{
                    q.push(ele->left);
                    q.push(ele->right);

                    string t = to_string(ele->val);
                    for(auto ele:t){
                        s.push_back(ele);
                    }
                }
                s.push_back('|');
            }
        }
        // cout<<s<<"\n";
        return s;
    }

    TreeNode* attach (string &s, int &itr){
        string temp = "";
        while(s[itr]!='|'){
            if(s[itr]=='#'){
                itr+=2;
                return nullptr;
            }
            temp.push_back(s[itr]);
            itr++;
        }
        // cout<<temp<<"\n";
        int num = stoi(temp);
        itr++;
        return new TreeNode(num);
    }

    TreeNode* negate(string &s){
        if(s=="") return nullptr;

        queue<TreeNode*>q;
        int itr=0;

        TreeNode* root = attach(s,itr);

        q.push(root);
        // itr++;

        while(!q.empty() && itr<s.size()){
            vector<TreeNode*>temp;

            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }

            for(auto ele:temp){
                ele->left = attach(s,itr);
                if(ele->left!=nullptr) q.push(ele->left);

                ele->right = attach(s,itr);
                if(ele->right!=nullptr) q.push(ele->right);
            }
        }

        return root;
    }



    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return traverse(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return negate(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
