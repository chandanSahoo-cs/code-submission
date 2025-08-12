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
    int traverse(TreeNode* node, int &sum){
        if(node==nullptr) return 0;

        int left = traverse(node->left,sum);
        int right = traverse(node->right,sum);
        sum = max({sum,left+right+node->val,left+node->val,right+node->val,node->val});

        int currSum = max(left,right);
        return max(node->val,currSum+node->val);
    }

    int maxPathSum(TreeNode* root) {
        int sum=-1e5;
        traverse(root,sum);
        return sum;
    }
};
