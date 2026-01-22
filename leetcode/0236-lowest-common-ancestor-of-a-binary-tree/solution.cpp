/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = nullptr;
    int lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr) return 0;

        int l = lca(root->left,p,q);
        int r = lca(root->right,p,q);

        int tot = (root==p || root==q)+l+r;

        if(tot==2 && ans==nullptr){
            ans = root;
        }

        return tot;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root,p,q);
        return ans;
    }
};
