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
    pair<TreeNode*,int> findAncestor(TreeNode* root){
        if(!root) return {root,0};
        
        auto [lcaL, depL] = findAncestor(root->left);
        auto [lcaR, depR] = findAncestor(root->right);

        if(depL>depR){
            return {lcaL,depL+1};
        }else if(depR>depL){
            return {lcaR,depR+1};
        }

        return {root,depL+1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto[node, dep] = findAncestor(root);

        return node;    
    }
};
