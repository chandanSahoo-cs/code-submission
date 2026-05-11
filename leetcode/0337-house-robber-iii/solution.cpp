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
    pair<int,int>rec(TreeNode* root){
        if(!root) return {0,0};

        auto [ltake, lskip] = rec(root->left);
        auto [rtake, rskip] = rec(root->right);

        int take = root->val+lskip+rskip;

        int skip = max(ltake,lskip)+max(rtake,rskip);

        return {take,skip};
    }

    int rob(TreeNode* root) {
        auto [take,skip] = rec(root);

        return max(take,skip);
    }
};
