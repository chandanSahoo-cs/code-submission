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
    int mx = 0;
    pair<int,int> dfs(TreeNode* root, int src){
        if(root==nullptr) return {0,false};

        auto [lft,lp] = dfs(root->left,src);
        auto [rght,rp] = dfs(root->right,src);

        if(root->val==src){
            mx = max({mx,lft,rght});
            return {0,true};
        }else if(lp || rp){
            mx = max(lft+1+rght,mx);
            return {lp?1+lft:1+rght,true};
        }

        return {max(lft,rght)+1,false};
    }

    int amountOfTime(TreeNode* root, int start) {
        dfs(root,start);
        return mx;
    }
};
