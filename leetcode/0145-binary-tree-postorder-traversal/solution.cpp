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

 // iterative
class Solution {
public:

    void iterativePostorder(stack<TreeNode*>&st, vector<int>&ans){
        if(st.empty()) return ;

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->left!=nullptr) st.push(temp->left);
            if(temp->right!=nullptr) st.push(temp->right);
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;   
        if(root!=nullptr){
            st.push(root);
        }
        iterativePostorder(st,ans);

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
