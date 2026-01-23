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

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        stack<tuple<TreeNode*,int,int>>st;

        TreeNode* root = new TreeNode(-1);

        st.push({root,0,nums.size()-1});

        while(!st.empty()){
            auto [node,l,r] = st.top();
            st.pop();
        
            int mid = (l+r)/2;
            node->val = nums[mid];


            if(mid+1<=r){
                node->right = new TreeNode(-1);
                st.push({node->right,mid+1,r});
            }

            if(l<=mid-1){
                node->left = new TreeNode(-1);
                st.push({node->left,l,mid-1});
            }
        }

        return root;
    }
};
