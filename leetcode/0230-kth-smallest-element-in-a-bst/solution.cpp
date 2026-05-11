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
    void dfs(TreeNode* root, int &ind, int k){
        
        if(root->left) dfs(root->left,ind,k);
        ind++;
        if(ind==k) ans = root->val;

        if(root->right) dfs(root->right,ind,k);

        return; 
    }

    int kthSmallest(TreeNode* root, int k) {
        int ind = 0;
        dfs(root,ind,k);

        return ans;
    }
};
