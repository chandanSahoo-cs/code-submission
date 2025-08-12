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
    void traverse(TreeNode* node, int &mx,int cnt){
        if(node==nullptr){
            mx=max(mx,cnt);
            return;
        }
        cnt++;
        traverse(node->left,mx,cnt);
        traverse(node->right,mx,cnt);
    }
    int maxDepth(TreeNode* root) {
        int mx=0; 
        traverse(root,mx,0);

        return mx;
    }
};
