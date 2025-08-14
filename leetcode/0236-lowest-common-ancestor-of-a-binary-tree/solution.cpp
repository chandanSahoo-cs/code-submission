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
    // TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode*q){
    //     if(!node) return nullptr;
    //     if(node->val==p->val) return p;
    //     if(node->val==q->val) return q;

    //     TreeNode * left = lowestCommonAncestor(node->left,p,q);
    //     TreeNode* right = lowestCommonAncestor(node->right,p,q);

    //     if(left==nullptr && right==nullptr) return nullptr ;
    //     else if(left!=nullptr && right!=nullptr) return node;
    //     else if(left!=nullptr) return left;
    //     else if(right!=nullptr) return right;
        
    //     return nullptr;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node) return nullptr;
        if(node->val==p->val) return p;
        if(node->val==q->val) return q;

        TreeNode * left = lowestCommonAncestor(node->left,p,q);
        TreeNode* right = lowestCommonAncestor(node->right,p,q);

        if(left==nullptr && right==nullptr) return nullptr ;
        else if(left!=nullptr && right!=nullptr) return node;
        else if(left!=nullptr) return left;
        else if(right!=nullptr) return right;
        
        return nullptr;   
    }
};
