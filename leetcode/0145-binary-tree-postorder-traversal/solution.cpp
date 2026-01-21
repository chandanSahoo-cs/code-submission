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
//go left -> then go right | if no right start pushing until temp!=st.top()->right;
    void postorder(TreeNode* root, vector<int>&ans){
        stack<TreeNode*>st;
        TreeNode* curr = root;

        while(curr!=nullptr || !st.empty()){
            if(curr!=nullptr){
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode* temp = st.top()->right;

                if(temp==nullptr){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    while(!st.empty() && temp==st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }else{
                    curr = temp;
                }
            }
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root, ans);
        return ans;
    }
};
