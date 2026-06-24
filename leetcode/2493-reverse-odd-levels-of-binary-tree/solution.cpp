/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);

        int level = 0;

        while(!q.empty()){
            
            int sz = q.size();

            vector<int>children;
            vector<TreeNode*>parent;

            for(int i=0;i<sz;i++){
                TreeNode* curr = q.front();
                q.pop();

                parent.push_back(curr);

                if(curr->left){
                    q.push(curr->left);
                    children.push_back(curr->left->val);
                }
                if(curr->right){
                    q.push(curr->right);
                    children.push_back(curr->right->val);
                }
            }

            int m = children.size();
            int j = m-1;

            if(!(level&1)){
                for(auto ele:parent){
                    if(ele->left){
                        ele->left->val = children[j];
                        j--;
                    }
                    if(ele->right){
                        ele->right->val = children[j];
                        j--;
                    }
                }

            }

            level++;
        }

        return root;
    }
};
