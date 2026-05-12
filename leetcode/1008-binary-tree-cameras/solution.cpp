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
    // tuple<int,int,int> = {not covered, covered with camera, covered without camera}
    const int INF = 1e9;

    tuple<int,int,int> rec(TreeNode* root){
        if(!root) return {INF,INF,0};

        auto [l0,l1,l2] = rec(root->left);
        auto [r0,r1,r2] = rec(root->right);

        int s0 = l2+r2;
        int s1 = 1+min({l0,l1,l2})+min({r0,r1,r2});
        int s2 = min(l1+min(r1,r2),r1+min(l1,l2));

        return {s0,s1,s2};
    }

    int minCameraCover(TreeNode* root) {
        auto [s0,s1,s2] = rec(root);

        return min(s1,s2);
    }
};
