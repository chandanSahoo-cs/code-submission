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
    TreeNode* invertTree(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>>q;
        
        TreeNode* curr = new TreeNode();

        if(root) q.push({root,curr});
        else return nullptr;

        while(!q.empty()){
            auto [root, curr] =q.front();
            q.pop();

            curr->val = root->val;
            
            if(root->left){
                curr->right = new TreeNode();
                q.push({root->left,curr->right});
            }

            if(root->right){
                curr->left = new TreeNode();
                q.push({root->right,curr->left});
            }
        }

        return curr;
    }
};
