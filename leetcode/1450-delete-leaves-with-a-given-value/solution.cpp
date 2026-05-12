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
    bool traverse(TreeNode* root, int target){
        if(!root) return true;

        bool left = traverse(root->left,target);
        bool right = traverse(root->right,target);

        if(left) root->left = nullptr;
        if(right) root->right = nullptr;

        if(left && right && root->val==target){
            return true;
        }

        return false;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(traverse(root,target)) return nullptr;
        return root;
    }
};
