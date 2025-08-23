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

    TreeNode* first=nullptr;
    TreeNode* middle=nullptr;
    TreeNode* end=nullptr;
    TreeNode* prev=nullptr;

    void traverse(TreeNode* root){
        if(root==nullptr) return;
        traverse(root->left);
        if(prev!=nullptr && prev->val>root->val){
            if(first==nullptr){
                first=prev;
                middle=root;
            }else{
                end=root;
                return;
            }
        }
        prev=root;
        traverse(root->right);
    }

    void recoverTree(TreeNode* root) {
        
        traverse(root);

        if(end==nullptr){
            swap(first->val, middle->val);
        }else swap(first->val,end->val);
    }
};
