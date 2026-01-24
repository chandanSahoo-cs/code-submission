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
class BSTIterator {
public:
    TreeNode* curr;
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        while(curr!=nullptr){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        int ans = curr->val;

        curr = curr->right;

        return ans;
    }
    
    bool hasNext() {
        return !st.empty() || curr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
