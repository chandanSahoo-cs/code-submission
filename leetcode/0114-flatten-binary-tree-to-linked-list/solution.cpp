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

    void flatten(TreeNode* root) {
        if(!root) return ;

        TreeNode* curr = root;

        while(curr){
            if(!curr->left){
                curr = curr->right;
            }else{
                TreeNode* temp = curr->left;

                while(temp->right!=nullptr && temp->right!=curr){
                    temp = temp->right;
                }

                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
                curr = curr->right;

                // if(temp->right==nullptr){
                //     temp->right = curr;
                //     curr = curr->left;
                // }else{
                // }
            }
        }



        return ;    
    }
};
