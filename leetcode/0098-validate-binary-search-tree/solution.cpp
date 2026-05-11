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

#define ll long long
class Solution {
public:

    bool dfs(TreeNode* root, ll mn, ll mx){
        ll vl = root->val;

        if(mn>=vl || vl>=mx) return false;

        bool flag = true;

        if(root->left){
            flag&=dfs(root->left,mn,vl);
        }

        if(root->right){
            flag&=dfs(root->right,vl,mx);
        }

        return flag;
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root,LLONG_MIN,LLONG_MAX);
    }
};
