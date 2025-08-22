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
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        while(node!=nullptr){
            int nv = node->val;
            if(nv> p->val && nv> q->val){
                node=node->left;
            }else if (nv<p->val && nv<q->val){
                node=node->right;
            }else return node;
        }

        return node;
    }
};
