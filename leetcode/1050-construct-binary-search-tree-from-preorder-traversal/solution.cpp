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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*>st;
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        TreeNode* prev=nullptr;

        for(int i=1;i<n;i++){
            if(st.top()->val>preorder[i]){
                st.top()->left=new TreeNode(preorder[i]);
                st.push(st.top()->left);
            }else if(st.top()->val<preorder[i]){
                while((prev==nullptr || preorder[i]>prev->val) && (!st.empty() && preorder[i]>st.top()->val)){
                    prev=st.top();
                    st.pop();
                }
                prev->right=new TreeNode(preorder[i]);
                st.push(prev->right);
            }
        }
        return root;
    }
};
