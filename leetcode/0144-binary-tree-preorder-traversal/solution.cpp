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

 // Iterative Way
class Solution {
public:

    void iterativePreorder(stack<TreeNode*>&st,vector<int>&ans){
        if(st.empty()) return;
        
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right!=nullptr) st.push(temp->right);
            if(temp->left!=nullptr) st.push(temp->left);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        if(root!=nullptr){
            st.push(root);
        }
        iterativePreorder(st,ans);

        return ans;
    }
};
