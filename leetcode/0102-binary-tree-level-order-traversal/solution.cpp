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

    void level(vector<vector<int>>&ans,queue<TreeNode*>&q){
        if(q.empty()) return;
        vector<TreeNode*>st;
        vector<int>val;
        while(!q.empty()){
            st.push_back(q.front());
            val.push_back(q.front()->val);
            q.pop();
        }
        ans.push_back(val);

        for(auto ele:st){
            if(ele->left!=nullptr){
                q.push(ele->left);
            }
            if(ele->right!=nullptr){
                q.push(ele->right);
            }
        }
        level(ans,q);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root!=nullptr) q.push(root);

        level(ans,q);

        return ans;
    }
};
