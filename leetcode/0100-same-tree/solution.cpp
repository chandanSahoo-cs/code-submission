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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((p && !q) || (!p && q)) return false;
         
        if(p->val!=q->val){
            return false;
        }

        bool l=true, r = true;

        if((p->left!=nullptr && q->left==nullptr) || (p->left==nullptr && q->left!=nullptr)){
            l=false;
        }else if(p->left && q->left){
            l = isSameTree(p->left,q->left);
        }

        if((p->right!=nullptr && q->right==nullptr) || (p->right==nullptr && q->right!=nullptr)){
            r=false;
        }else if(p->right && q->right){
            r = isSameTree(p->right,q->right);
        }

        return l && r;
    }
};
