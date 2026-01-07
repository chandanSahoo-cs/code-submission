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

    const int mod = 1e9+7;

    long long mx = -1;

    int sum(TreeNode* root){
        if(root==nullptr) return 0;
        return sum(root->left)+root->val+sum(root->right);
    }

    int mxProd(TreeNode* root,int total){
        if(root==nullptr){
            return 0;
        }

        int left = mxProd(root->left,total);
        int right = mxProd(root->right,total);

        mx = max((total-left)*1LL*left,mx);
        mx = max((total-right)*1LL*right,mx);

        return left+root->val+right;
    }

    int maxProduct(TreeNode* root) {
        
        int total = sum(root);
        mxProd(root,total);

        return mx%mod;

    }
};
