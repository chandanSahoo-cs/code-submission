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
    bool flag = true;
    pair<ll,ll> search(TreeNode* root){
        if(root==nullptr) return {LLONG_MIN,LLONG_MAX};

        auto [ largestL, smallestL] = search(root->left);
        auto [ largestR, smallestR] = search(root->right);

        if(root->val>largestL && root->val<smallestR){
            return {max((ll)root->val,largestR),min((ll)root->val,smallestL)};
        }
        flag = false;

        return {LLONG_MAX,LLONG_MIN};
    }

    bool isValidBST(TreeNode* root) {
        search(root);
        return flag;  
    }
};
