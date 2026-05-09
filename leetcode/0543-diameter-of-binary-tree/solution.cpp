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
    int mx = 0;

    int diameter(TreeNode* root){
        
        int left = 0, right = 0;

        if(root->left) left = diameter(root->left);
        if(root->right) right = diameter(root->right);

        mx = max(mx,left+right);

        return 1+max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);

        return mx;
    }
};
