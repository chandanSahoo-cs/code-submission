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
    int traverse(TreeNode* root, int &dt){
        if(root==nullptr) return 0;

        int left = traverse(root->left,dt);
        int right = traverse(root->right,dt);
        
        dt = max(dt,left+right);
        int height = max(left,right);

        return height+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dt=0;
        traverse(root,dt);

        return dt;
    }
};
