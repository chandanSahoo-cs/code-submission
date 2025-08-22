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
    bool traverse(TreeNode* node, TreeNode** prev){
        if(node==nullptr){
            return true;
        }
        bool left =  traverse(node->left,prev);
        bool mid=true;
        if(*prev!=nullptr && (*prev)->val>=node->val){
            return false;
        }
        *prev=node;
        bool right = traverse(node->right,prev);

        return left && mid && right;
    }

    bool isValidBST(TreeNode* root) {
        TreeNode*prev=nullptr;
        return traverse(root,&prev);
    }
};
