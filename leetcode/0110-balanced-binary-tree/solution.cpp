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
    int dfs(TreeNode* root, bool &flag){
        if(root==nullptr) return 0;

        int l = dfs(root->left,flag);
        int r = dfs(root->right,flag);

        if(abs(r-l)>1) flag=false;

        return max(l,r)+1;
    }

    bool isBalanced(TreeNode* root) {
        bool flag=true;
        dfs(root,flag);

        return flag;
    }
};
