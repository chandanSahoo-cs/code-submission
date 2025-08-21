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
    TreeNode* insert(TreeNode*root,int key){
        TreeNode* prev = nullptr;
        TreeNode* curr = root;

        while(curr!=nullptr){
            if(curr->val == key){
                break;
            }else if(curr->val>key){
                prev=curr;
                curr=curr->left;
            }else{
                prev=curr;
                curr=curr->right;
            }
        }

        if(curr==nullptr) return root;

        TreeNode* insertNode=nullptr;

        if(curr->right==nullptr){
            insertNode = curr->left;
        }else{
            TreeNode* node = curr->right;

            while(node->left!=nullptr){
                node=node->left;
            }
            node->left=curr->left;
            insertNode = curr->right;

        }

        TreeNode* ans = root;

        if(prev==nullptr){
            ans=insertNode;
        }else{
            if(prev->left!=nullptr && prev->left->val==key){
                prev->left=insertNode;
            }else {
                prev->right=insertNode;
            }
        }

        return ans;

    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return insert(root,key);
    }
};
