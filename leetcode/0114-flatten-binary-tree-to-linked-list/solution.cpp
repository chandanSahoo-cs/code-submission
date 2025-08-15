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
    void traverse(TreeNode* node, TreeNode** prev){
        if(node == nullptr) return;

        traverse(node->right,prev);
        traverse(node->left,prev);

        node->right = *prev;
        node->left = nullptr;
        *prev = node;
    }

    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        traverse(root,&prev);
    }
};
