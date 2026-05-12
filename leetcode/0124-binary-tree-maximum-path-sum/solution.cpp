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
    int mx = INT_MIN;

    int rec(TreeNode* root){
        if(!root) return 0;

        int left = rec(root->left);
        int right = rec(root->right);

        mx = max(mx,left+root->val+right);

        return max(0,root->val+max(left,right));
    }

    int maxPathSum(TreeNode* root) {
        rec(root);

        return mx;
    }
};
