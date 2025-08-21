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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        if(node==nullptr){
            return new TreeNode(val);
        }
        while(node!=nullptr){
            if(val>node->val){
                if(node->right!=nullptr){
                    node=node->right;
                }else{
                    node->right=new TreeNode(val);
                    break;
                }
            }else{
                if(node->left!=nullptr){
                    node=node->left;
                }else{
                    node->left= new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};
