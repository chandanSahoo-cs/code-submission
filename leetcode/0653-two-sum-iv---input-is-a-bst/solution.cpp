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
    bool findK(TreeNode* root, int val){
        if(root==nullptr) return false;
        if(root->val==val) return true;

        if(root->val>val) return findK(root->left,val);
        
        return findK(root->right,val);
    }

    int findMx(TreeNode* root){
        if(root->right==nullptr) return root->val;

        return findMx(root->right);
    }

    int findMn(TreeNode* root){
        if(root->left==nullptr) return root->val;

        return findMn(root->left);
    }

    bool findTarget(TreeNode* root, int k) {
        int mn = findMn(root);
        int mx = findMx(root);

        for(int i=mn;i<=mx;i++){
            if(i==k-i) continue;
            if(findK(root,i) && findK(root,k-i)) return true;
        }

        return false;
    }
};
