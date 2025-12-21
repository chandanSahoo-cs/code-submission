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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        stack<TreeNode*>st;
        stack<int>hold;

        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            hold.push(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }

        vector<int>ans;

        while(!hold.empty()){
            ans.push_back(hold.top());
            hold.pop();
        }

        return ans;
    }
};
