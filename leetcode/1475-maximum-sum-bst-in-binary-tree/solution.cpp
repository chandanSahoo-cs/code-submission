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
    int sum = 0;
    tuple<int,int,int> search(TreeNode* root){
        if(root==nullptr) return {0,INT_MIN,INT_MAX};

        auto [ sumL, largestL, smallestL] = search(root->left);
        auto [ sumR, largestR, smallestR] = search(root->right);

        if(root->val>largestL && root->val<smallestR){
            sum = max(sum,sumL+sumR+root->val);
            return {sumL+sumR+root->val,max(root->val,largestR),min(root->val,smallestL)};
        }

        return {0,INT_MAX,INT_MIN};
    }

    int maxSumBST(TreeNode* root) {
        search(root);

        return sum;
    }
};
