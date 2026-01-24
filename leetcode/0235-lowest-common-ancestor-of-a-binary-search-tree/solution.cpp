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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root==p || root==q) return root;
        if(p->val<root->val && q->val>root->val) return root;

        if(p->val<root->val && q->val<root->val) return lca(root->left,p,q);
        
        return lca(root->right,p,q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val){
            TreeNode* temp = p;
            p = q;
            q = temp;
        }
        return lca(root,p,q);
    }
};
