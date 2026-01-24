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
    int ans = -1;

    void search(TreeNode* root, int k, int &ind){
        if(root==nullptr) return;

        search(root->left,k,ind);
        ind++;
        if(ind==k){
            ans = root->val;
        }

        search(root->right,k,ind);

        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        int ind = 0;
        search(root,k,ind);

        return ans;
    }
};
