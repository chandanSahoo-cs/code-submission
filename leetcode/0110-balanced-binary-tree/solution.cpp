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
    int traverse(TreeNode* node,int &diff){
        if(node==nullptr) {
            return 0;
        }

        int left = traverse(node->left,diff);
        int right = traverse(node->right,diff);

        diff=max(diff,abs(left-right));
        int height=max(left,right);

        return height+1;
    }

    bool isBalanced(TreeNode* root) {
        int diff=0;
        traverse(root,diff);

        if(diff>1) return false;
        return true;
    }
};
