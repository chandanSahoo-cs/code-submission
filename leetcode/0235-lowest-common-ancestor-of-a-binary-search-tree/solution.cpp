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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while(true){
            int vl = curr->val;
            if(p->val<vl && q->val<vl){
                curr = curr->left;
            }else if(p->val>vl && q->val>vl){
                curr = curr->right;
            }else break;
        }

        return curr;
    }
};
