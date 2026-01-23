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
    TreeNode* build(vector<int>& preorder, int &ind, int ub){
        int n = preorder.size();
        if(ind==n) return nullptr;

        if(preorder[ind]<ub){
            TreeNode* newNode = new TreeNode(preorder[ind]);
            ind++;
            newNode->left = build(preorder,ind,newNode->val);
            newNode->right = build(preorder,ind,ub);
            return newNode;
        }

        return nullptr;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return build(preorder,ind,INT_MAX);
    }
};
