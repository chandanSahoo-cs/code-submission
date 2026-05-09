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
    bool flag=true;
    
    int dfs(TreeNode* root){
        int left = 0, right = 0;

        if(root->left) left = dfs(root->left);
        if(root->right) right = dfs(root->right);

        if(abs(left-right)>1) flag=false;

        return 1+max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        if(root){
            dfs(root);
            return flag;
        }

        return true;
    }
};
